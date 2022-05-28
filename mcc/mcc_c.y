%skeleton "lalr1.cc"
%require "3.8.1"
%code requires{
#include <utility>
#include "mcc_utils.hpp"
void yyerror(char *s);
class driver;
}
%locations
%define api.token.raw
// Allows us to construct a parser instance in driver
%define api.token.constructor
%define api.value.type variant
%define parse.trace
%define parse.error detailed
// Look-ahead correction
%define parse.lac full
// Avoid name clashes in generated files
%define api.token.prefix {TOK_}

%token
	IDENTIFIER "identifier"
	CONSTANT "constant"
	STRING_LITERAL "literal"
	SIZEOF "sizeof"
	TYPEDEF "typedef"
	EXTERN "extern"
	STATIC "static"
	AUTO "auto"
	REGISTER "register"
	CHAR "char"
	SHORT "short"
	LONG "long"
	SIGNED "signed"
	UNSIGNED "unsigned"
	FLOAT "float"
	DOUBLE "double"
	CONST "const"
	VOLATILE "volatile"
	VOID "void"
	CASE "case"
	DEFAULT "default"
	IF "if"
	INT "int"
	ELSE "else"
	SWITCH "switch"
	WHILE "while"
	DO "do"
	FOR "for"
	GOTO "goto"
	CONTINUE "continue"
	BREAK "break"
	RETURN "return"
	STRUCT "struct"
	UNION "union"
	ENUM "enum"
	DIV_ASSIGN "/="
	MOD_ASSIGN "%="
	MUL_ASSIGN "*="
	SUB_ASSIGN "-="
	ADD_ASSIGN "+="
	LEFT_ASSIGN "<<="
	RIGHT_ASSIGN ">>="
	AND_ASSIGN "&="
	XOR_ASSIGN "^="
	OR_ASSIGN "|="
	TYPE_NAME "typename"
	NL "\n"
	PLUS "+"
	MINUS "-"
	MUL "*"
	DIV "/"
	XOR "^"
	SHL "<<"
	SHR ">>"
	OR "|"
	AND "&"
	MOD "%"
	ASS "="
	NOT "!"
	FLIP "~"
	LEFT_PAR "("
	RIGHT_PAR ")"
	PTR "->"
	L_CURLY "{"
	R_CURLY "}"
	L_SQBR "["
	R_SQBR "]"
	ELLIPSIS "..."
	INC "++"
	DEC "--"
	EQ "=="
	GEQ ">="
	LEQ "<="
	NEQ "!="
	SEMI ";"
	DOT "."
	COMMA ","
	COL ":"
	LE "<"
	GE ">"
	LOR "&&"
	LAND "||"
	Q_MARK "?"
	;
%token END 0 "end of file"
%nonassoc "if"
%nonassoc "else"
%type <std::size_t> array_dim;
%type <std::vector<std::pair<std::string,mcc::Symbol>>> parameter_type_list
%type <std::vector<std::pair<std::string,mcc::Symbol>>> parameter_declaration parameter_list;
%type <std::vector<std::size_t>> array_dim_list;
%type <mcc::Symbol> init_declarator;
%type <std::vector<mcc::Symbol>> init_declarator_list;
%type <std::string> "identifier";
%type <mcc::Symbol> primary_expression;
%type <mcc::Symbol> postfix_expression
%type <mcc::Symbol> expression;
%type <mcc::Symbol> "literal";
%type <mcc::Symbol> "constant";
%type <mcc::T> declaration_specifiers;
%type <mcc::T> type_specifier;
%type <mcc::Symbol> cast_expression multiplicative_expression additive_expression;
%type <mcc::Symbol> shift_expression relational_expression equality_expression;
%type <mcc::Symbol> and_expression exclusive_or_expression inclusive_or_expression
%type <mcc::Symbol> logical_and_expression logical_or_expression constant_expression
%type <mcc::Symbol> conditional_expression assignment_expression unary_expression
%type <mcc::PtrBits> pointer;
%type <std::pair<std::string,mcc::Symbol>> id_or_idptr direct_declarator declarator
;
%type <std::string> "typename";
%type <std::string> type_qualifier;
%type <std::string> type_qualifier_list;
%type <mcc::T> type_name;
%type <mcc::T> specifier_qualifier_list;
%param { driver& drv }
%code {
# include "driver.h"
}
%start translation_unit
%%

primary_expression
	: "identifier"
	{
		const auto sym = drv.GetSymbol(drv.GetCurrentScope()+$1);
		if(sym)
		{
			$$=sym.value();
		}
		else
		{
			const auto global_lookup = drv.GetSymbol("@::"+$1);
			if(global_lookup)
			{
				$$=global_lookup.value();
			}
			else
			{
				$$={};
			}
		}
	}
	| "constant"
	{
		$$=$1;
	}
	| "literal"
	{
		$$=$1;
	}
	| "(" expression ")"
	{
	$$=$2;
	}
	;

postfix_expression
	: primary_expression
	{
		$$=$1;
	}
	| postfix_expression "[" expression "]"
	{
		const auto is_sub_int = mcc::IsIntegerT($3.GetType());
		const auto ind = $3.GetIndLevel();
		if(!is_sub_int || $3.IsPtr())
			{
				mcc::PrintColored("Array subscript can't be non integer",mcc::TextColor::Error);
			}

		else if( $1.IsPtr())
		{
			const auto ind_lhs = $1.GetIndLevel();
			$$={{$1.GetType(),$1.GetDeref()},$1.DerefIsConst(),true,false};
					}
		else if(std::holds_alternative<mcc::CArray>($1.GetType()))
		{
			auto arr_t = std::get<mcc::CArray>($1.GetType());
			auto deref_t = arr_t.GetDerefT();
			$$={{deref_t},true,true,false};
					}
		else
		{
			mcc::PrintColored("Cannot apply subscript operator to a non pointer value",mcc::TextColor::Error);
		}
	}
	| postfix_expression "(" ")"
	{
		if(mcc::IsFuncPtr($1))
		{
			const auto ftype = std::get<std::shared_ptr<mcc::Func>>($1.GetType());
			$$={ftype->GetReturnType(),false,true,false};
		}
		else
		{
			mcc::PrintColored("Is not a function",mcc::TextColor::Error);
			$$={};
		}
		mcc::PrintColored("Function call with no args",mcc::TextColor::Good);
	}
	| postfix_expression "(" argument_expression_list ")"
	{mcc::PrintColored("Function call with args",mcc::TextColor::Good);}
	| postfix_expression "." "identifier"
	{mcc::PrintColored("Non ptr struct or union field access",mcc::TextColor::Good);}
	| postfix_expression "->" "identifier"
	{mcc::PrintColored("Ptr struct or union field access",mcc::TextColor::Good);}
	| postfix_expression "++"
	{mcc::PrintColored("Postfix increment",mcc::TextColor::Good);}
	| postfix_expression "--"
	{mcc::PrintColored("Postfix decrement",mcc::TextColor::Good);}
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list "," assignment_expression
	;

unary_expression
	: postfix_expression
	{$$=$1;}
	| "++" unary_expression
	{$$=$2;}
	| "--" unary_expression
	{$$=$2;}
	| unary_operator cast_expression
	{$$=$2;}
	| "sizeof" unary_expression
	{$$=mcc::Symbol({mcc::Primitive::ULongLong,0},true,true,false);}
	| "sizeof" "(" type_name ")"
	{$$=mcc::Symbol({mcc::Primitive::ULongLong,0},true,true,false);}

	;

unary_operator
	: "+"
	| "*"
	| "&"
	| "-"
	| "~"
	| "!"
	;

cast_expression
	: unary_expression
	{$$=$1;}
	| "(" type_name ")" cast_expression
	{$$=mcc::Symbol{$2,true,true,false};}
	;

multiplicative_expression
	: cast_expression
	{$$=$1;}
	| multiplicative_expression "*" cast_expression
	| multiplicative_expression "/" cast_expression
	| multiplicative_expression "%" cast_expression
	;

additive_expression
	: multiplicative_expression
	{$$=$1;}

	| additive_expression "+" multiplicative_expression
	| additive_expression "-" multiplicative_expression
	;

shift_expression
	: additive_expression
	{$$=$1;}

	| shift_expression "<<" additive_expression
	| shift_expression ">>" additive_expression
	;

relational_expression
	: shift_expression
	{$$=$1;}

	| relational_expression "<=" shift_expression
	| relational_expression ">=" shift_expression
	| relational_expression "<" shift_expression
	| relational_expression ">" shift_expression
	;

equality_expression
	: relational_expression
	{$$=$1;}

	| equality_expression "==" relational_expression
	| equality_expression "!=" relational_expression
	;

and_expression
	: equality_expression
	{$$=$1;}

	| and_expression "&" equality_expression
	;

exclusive_or_expression
	: and_expression
	{$$=$1;}

	| exclusive_or_expression "^" and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	{$$=$1;}

	| inclusive_or_expression "|" exclusive_or_expression
	;
logical_and_expression
	: inclusive_or_expression
	{$$=$1;}

	| logical_and_expression "||" inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	{$$=$1;}

	| logical_or_expression "&&" logical_and_expression
	;

conditional_expression
	: logical_or_expression
	{$$=$1;}
	| logical_or_expression {
		const auto is_primitive = std::holds_alternative<mcc::Primitive>($1.GetType());
		const auto is_ptr = $1.IsPtr();
		if(!is_primitive && !is_ptr)
		{
			mcc::PrintColored("Could not evaluate as pointer or arithmetic type",mcc::TextColor::Error);
		}
		else if(std::get<mcc::Primitive>($1.GetType())==mcc::Primitive::Void)
		{
			mcc::PrintColored("Void where pointer or arithmetic type is required",mcc::TextColor::Error);
		}
	}
	"?" expression ":" conditional_expression
		;

assignment_expression
	: conditional_expression
	{$$=$1;}
	| unary_expression
	{
		if(!$1.IsLvalue()||$1.IsConst())
		{mcc::PrintColored("Can only assign to a non-const lvalue",mcc::TextColor::Error);}
	}
	assignment_operator assignment_expression
	{
		if($1.GetType().index()!=$4.GetType().index())
		{
			mcc::PrintColored("Cant assign a non primitive to a primitive or vise-versa",mcc::TextColor::Error);
		}
	}
	;

assignment_operator
	: "="
	| "*="
	| "/="
	| "%="
	| "+="
	| "-="
	| "<<="
	| ">>="
	| "&="
	| "^="
	| "|="
	;

expression
	: assignment_expression
	{$$=mcc::Symbol({$1.GetType(),$1.GetIndLevel()},false,true,true);}
	| expression "," assignment_expression
	;

constant_expression
	: conditional_expression
	;
// check current scope
declaration
	: declaration_specifiers ";"
	{mcc::PrintColored("declaration does not declare anything",mcc::TextColor::Warning);}
	| declaration_specifiers init_declarator_list ";"
	{
		drv.UnsetCurrentType();
	}
	;
// must return a type
declaration_specifiers
	: storage_class_specifier
	{
		$$={mcc::Primitive::Int};
		drv.SetCurrentType($$);
	}
	| storage_class_specifier declaration_specifiers
	{
		$$=$2;drv.SetCurrentType($$);
	}
	| type_specifier
	{
		$$=$1;
		drv.SetCurrentType($$);
	}
	| type_specifier declaration_specifiers
	{
		$$={$1};
		drv.SetCurrentType($$);
	}
	| type_qualifier
	{
		$$={mcc::Primitive::Int};
		drv.SetCurrentType($$);}
	| type_qualifier declaration_specifiers
	{
		$$={$2};
		drv.SetCurrentType($$);
	}
	;

init_declarator_list
	: init_declarator
	{drv.SetInConst(false);}
	| init_declarator_list "," init_declarator
	;

init_declarator
	: declarator
	{
		auto sym = mcc::Symbol{drv.GetCurrentType(),drv.GetInConst(),true,true};
		drv.AddSymbol($1.first,$1.second);
	}
	| declarator "=" initializer
	{
		auto sym=mcc::Symbol{drv.GetCurrentType(),drv.GetInConst(),true,true};
		drv.AddSymbol($1.first,$1.second);
	}
	;

storage_class_specifier
	: "typedef"
	| "extern"
	| "static"
	| "auto"
	| "register"
	;

type_specifier
	: "void"{$$={mcc::Primitive::Void};}
	| "char"{$$={mcc::Primitive::Char};}
	| "short"{$$={mcc::Primitive::Short};}
	| "int"{$$={mcc::Primitive::Int};}
	| "long"{$$={mcc::Primitive::Long};}
	| "float"{$$={mcc::Primitive::Float};}
	| "double"{$$={mcc::Primitive::Double};}
	| "signed" {$$={mcc::Primitive::Int};}
	| "unsigned"{$$={mcc::Primitive::UInt};}
	| struct_or_union_specifier{}
	| enum_specifier{}
	| "typename"
		{
			$$ = drv.GetType($1).value();
		}

struct_or_union_specifier
	: struct_or_union "identifier" "{" struct_declaration_list "}"
	| struct_or_union "{" struct_declaration_list "}"
	| struct_or_union "identifier"
	;
struct_or_union
	: "struct"
	| "union"
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ";"
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	{
		if(std::holds_alternative<mcc::NoneType>($1.GetType())^std::holds_alternative<mcc::NoneType>($2.GetType()))
		{
			$$=$1;
		}
		else
		{
			mcc::PrintColored("Invalid type",mcc::TextColor::Error);
			$$={mcc::Primitive::Void};
		}
	}
	| type_specifier
	{$$=$1;}
	| type_qualifier specifier_qualifier_list
	{$$=$2;}
	| type_qualifier
	{$$={true};}
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list "," struct_declarator
	;

struct_declarator
	: declarator
	| ":" constant_expression
	| declarator ":" constant_expression| id_or_idptr "(" identifier_list  ")"
	{
		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
	}

	;

enum_specifier
	: "enum" "{" enumerator_list "}"
	| "enum" "identifier" "{" enumerator_list "}"
	| "enum" "identifier"
	;

enumerator_list
	: enumerator
	| enumerator_list "," enumerator
	;

enumerator
	: "identifier"
	| "identifier" "=" constant_expression
	;
type_qualifier
	: "const"{$$="const";drv.SetInConst(true);}
	| "volatile"{$$="";}
	;

declarator
	: pointer direct_declarator
	{
		$$=$2;
	}
	| direct_declarator
	{
		$$=$1;
	}
	;
id_or_idptr:
	"identifier"
	{
		$$={$1,{drv.GetCurrentType(),drv.GetInConst(),true,true}};
		//symbol has no indirection, i.e. int arr[] - array of int
	}
	|
	"(" "identifier" ")"
	{
		$$={$2,{drv.GetCurrentType(),drv.GetInConst(),true,true}};
	}
	//same as w/o braces
	|
	"(" pointer "identifier" ")"
	{
		$$={$3,{{drv.GetCurrentType().GetType(),$2.GetIndirection()},drv.GetInConst(),true,true}};
	//symbol HAS indirection, i.e int (*arr)[] - POINTER to an array of int
	}
array_dim:
	"[" constant_expression "]"
	{
		$$=1;
	}
	|"[" "]"
	{
		$$=0;
	}
	;
array_dim_list:
	array_dim
	{
		$$={};
		$$.push_back($1);
	}
	|array_dim_list array_dim
	{
		$$=$1;
		$$.push_back($2);
	}
	;
direct_declarator
	: id_or_idptr
	//return name for declarator
	{
		//this is name of the symbol or type idk
	}
	//return array of direct_declarator
	| id_or_idptr array_dim_list
	{
		auto as_arr_t = mcc::T{$1.second.GetType()}.ToArrT();
		drv.AddSymbol($1.first,{{mcc::CArray{as_arr_t,$2.begin(),$2.end()},$1.second.GetIndLevel()},drv.GetInConst(),true,false});
		mcc::PrintColored("Array:",mcc::TextColor::Good);
	}
	| id_or_idptr "(" parameter_type_list  ")"
	{
		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
	}
	| id_or_idptr "(" ")"
	{

	}

pointer
	: "*"
	{
		$$={};
		$$.AddIndirection(false);
	}
	| "*" type_qualifier_list
	{
		$$={};
		$$.AddIndirection($2=="const");
	}
	| "*" pointer
	{
		$$=$2;
		$$.AddIndirection(false);
	}
	| "*" type_qualifier_list pointer
	{
		$$=$3;
		$$.AddIndirection($2=="const");
	}

	;

type_qualifier_list
	: type_qualifier
	{$$=$1;}
	| type_qualifier_list type_qualifier
	{$$=$1+$2;}
	;


parameter_type_list
	: parameter_list
	{
		$$=$1;
	}
	| parameter_list "," "..."
	{$$=$1;}
	;

parameter_list
	: parameter_declaration
	{$$=$1;}
	| parameter_list "," parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	{
			auto decl = $2.second;
			mcc::PrintColored($2.first+"\n",mcc::TextColor::Warning);
			$$={};
			$$.push_back({$2.first,{$1,drv.GetInConst(),true,true}});
	}
	;

identifier_list
	: "identifier"
	| identifier_list "," "identifier"
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: "(" abstract_declarator ")"
	| "[" "]"
	| "[" constant_expression "]"
	| direct_abstract_declarator "[" "]"
	| direct_abstract_declarator "[" constant_expression "]"
	| "(" ")"
	| "(" parameter_type_list ")"
	| direct_abstract_declarator "(" ")"
	| direct_abstract_declarator "(" parameter_type_list ")"
	;

initializer
	: assignment_expression
	| "{" initializer_list "}"
	| "{" initializer_list "," "}"
	;

initializer_list
	: initializer
	| initializer_list "," initializer
	;

statement
	: labeled_statement
	| {drv.EnterNewScope("");}
		compound_statement
		{drv.LeaveScope();}
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	| declaration
	;
// Must fill list of tags and check on function exit list of tag refs and print
// error if no such tag exists
labeled_statement
	: "identifier" ":" statement
	{
		drv.AddLabel($1);
	}
	| "case" constant_expression ":" statement
	| "default" ":" statement
	;

// Anonymous scope if does not start with an identifier
compound_statement
	:"{"  statement_list "}"
	|"{" "}"
	;

statement_list
	: statement
	| statement_list statement
	;
expression_statement
	: ";"
	| expression ";"
	;

selection_statement
	: "if" "(" expression ")" statement %prec "if"
	| "if" "(" expression ")" statement "else" statement
	| "switch" "(" expression ")" statement
	;

iteration_statement
	: "while" "(" expression {mcc::EvalsToBool($3);} ")" statement
	| "do" statement "while" "(" expression {mcc::EvalsToBool($5);} ")" ";"
	| "for" "(" expression_statement expression_statement ")" statement

	{std::cout<<"param decl\n";}
	| "for" "(" expression_statement expression_statement expression ")" statement
	;

jump_statement
	: "goto" "identifier" ";"
	{
		drv.AddLabelRef($2);
	}
	| "continue" ";"
	| "break" ";"
	| "return" ";"
	| "return" expression ";"
	;
//nothing to do here
translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration //Global var or function declaration
	{mcc::PrintColored("New global definition",mcc::TextColor::Good);}
	;
//All kinds of functions definitions...
function_definition:
	 declaration_specifiers direct_declarator {drv.EnterNewScope($2.first);} compound_statement
		{drv.LeaveScope();}
	| direct_declarator
		{
			if(!mcc::IsFuncPtr($1.second))
			{
				//drv.AddSymbol();
				drv.EnterNewScope($1.first);
			}
			else
			{
			//bad
			}
		}
		compound_statement
		{drv.LeaveScope();}
	;

%%
void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
