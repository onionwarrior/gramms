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
%type <std::string> direct_declarator;
%type <mcc::Symbol> init_declarator;
%type <std::vector<mcc::Symbol>> init_declarator_list;
%type <std::string> "identifier";
%type <std::string> declarator
%type <mcc::Symbol> primary_expression;
%type <mcc::Symbol> postfix_expression
%type <mcc::Symbol> expression;
%type <mcc::Symbol> "literal"
%type <mcc::Symbol> "constant"
%type <mcc::type_t> declaration_specifiers;
%type <mcc::type_t> type_specifier;
%type <mcc::Symbol> cast_expression multiplicative_expression additive_expression;
%type <mcc::Symbol> shift_expression relational_expression equality_expression;
%type <mcc::Symbol> and_expression exclusive_or_expression inclusive_or_expression
%type <mcc::Symbol> logical_and_expression logical_or_expression constant_expression
%type <mcc::Symbol> conditional_expression assignment_expression unary_expression
%type <mcc::PtrBits> pointer;
%type <std::string> "typename";
%type <std::string> type_qualifier;
%type <std::string> type_qualifier_list;
%type <std::pair<mcc::type_t,mcc::PtrBits>> type_name;
%type <std::pair<mcc::type_t,mcc::PtrBits>> specifier_qualifier_list;
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
	| postfix_expression "[" expression "]"
	{
		const auto is_sub_int = mcc::IsIntegerT($3.GetType());
		const auto ind = $3.GetType().index();
		if( $1.IsPtr())
		{
			if(!is_sub_int || $3.IsPtr())
			{
				mcc::PrintColored("Array subscript can't be non integer",mcc::TextColor::Error);
			}
		}
		else
		{
			mcc::PrintColored("Cannot apply subscript operator to a non pointer value",mcc::TextColor::Error);
		}
	}
	| postfix_expression "(" ")"
	{mcc::PrintColored("Function call with no args",mcc::TextColor::Good);}
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
	{$$=mcc::Symbol(mcc::Primitive::ULongLong,0,true,true,false);}
	| "sizeof" "(" type_name ")"
	{$$=mcc::Symbol(mcc::Primitive::ULongLong,0,true,true,false);}

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
	{$$=mcc::Symbol{$2.first,$2.second.GetIndirection(),true,true,false};}
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
	| unary_expression assignment_operator assignment_expression
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
	{$$=mcc::Symbol($1.GetType(),$1.GetIndLevel(),false,true,true);}
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
		const auto t = $1;
		drv.UnsetCurrentType();
	}
	;
// must return a type
declaration_specifiers
	: storage_class_specifier
	{$$=mcc::Primitive::Int;drv.SetCurrentType($$);}
	| storage_class_specifier declaration_specifiers
	{$$=$2;drv.SetCurrentType($$);}
	| type_specifier
	{$$=$1;drv.SetCurrentType($$);}
	| type_specifier declaration_specifiers
	{$$=$1;drv.SetCurrentType($$);}
	| type_qualifier
	{$$=mcc::Primitive::Int;drv.SetCurrentType($$);}
	| type_qualifier declaration_specifiers
	{ $$=$2;drv.SetCurrentType($$);}
	;

init_declarator_list
	: init_declarator
	| init_declarator_list "," init_declarator
	;

init_declarator
	: declarator
	{
		auto sym = mcc::Symbol{drv.GetCurrentType(),0,false,true,true};
		drv.AddSymbol($1,std::move(sym));
	}
	| declarator "=" initializer
	{
		auto sym=mcc::Symbol{drv.GetCurrentType(),0,false,true,true};
		drv.AddSymbol($1,std::move(sym));
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
	: "void"{$$=mcc::Primitive::Void;}
	| "char"{$$=mcc::Primitive::Char;}
	| "short"{$$=mcc::Primitive::Short;}
	| "int"{$$=mcc::Primitive::Int;}
	| "long"{$$=mcc::Primitive::Long;}
	| "float"{$$=mcc::Primitive::Float;}
	| "double"{$$=mcc::Primitive::Double;}
	| "signed"
	{}
	| "unsigned"{}
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
	{$$=$1;}
	| type_specifier
	{$$=$1;}
	| type_qualifier specifier_qualifier_list
	{$$=$2;}
	| type_qualifier
	{$$={};}
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list "," struct_declarator
	;

struct_declarator
	: declarator
	| ":" constant_expression
	| declarator ":" constant_expression
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
	: "const"{$$="const";}
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

direct_declarator
	: "identifier"
	{$$=$1;}
	| "(" declarator ")"
	{$$=$2;}
	| direct_declarator  "[" constant_expression  "]"
	{
		mcc::PrintColored("Array def:",mcc::TextColor::Good);
		drv.AddSymbol($1,mcc::Symbol{drv.GetCurrentType(),1,true,true,true});
	}
	| direct_declarator "[" "]"
	{
		mcc::PrintColored("Array def VLA:",mcc::TextColor::Good);
		drv.AddSymbol($1,mcc::Symbol{drv.GetCurrentType(),1,true,true,true});
	}
	| direct_declarator "(" parameter_type_list ")"
	{ mcc::PrintColored("Function ptr only type proto",mcc::TextColor::Good);}
	| direct_declarator "(" identifier_list  ")"
	{
		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
	}
	| direct_declarator "(" ")"
	;

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
	| parameter_list "," "..."
	;

parameter_list
	: parameter_declaration
	| parameter_list "," parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
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

labeled_statement
	: "identifier" ":" statement
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
declaration_list
	:declaration
	| declaration_list declaration
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

	| "for" "(" expression_statement expression_statement expression ")" statement
	;

jump_statement
	: "goto" "identifier" ";"
	| "continue" ";"
	| "break" ";"
	| "return" ";"
	| "return" expression ";"
	;

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
function_definition
	: declaration_specifiers declarator declaration_list {drv.EnterNewScope($2);} compound_statement
		{drv.LeaveScope();}
	| declaration_specifiers declarator {drv.EnterNewScope($2);} compound_statement
		{drv.LeaveScope();}
	| declarator declaration_list {drv.EnterNewScope($1);} compound_statement
		{drv.LeaveScope();}
	| declarator {drv.EnterNewScope($1);} compound_statement
		{drv.LeaveScope();}
	;

%%
void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
