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
%type <std::string> enumerator
%type <std::vector<std::string>> enumerator_list;
%type <std::string> additive_operator multiplicative_operator shift_operator
%type <std::vector<std::pair<std::string,mcc::Symbol>>> parameter_type_list
%type <std::vector<mcc::Symbol>>argument_expression_list
%type <std::vector<std::pair<std::string,mcc::Symbol>>> parameter_declaration parameter_list;
%type <std::vector<std::size_t>> array_dim_list;
%type <mcc::Symbol> init_declarator;
%type <std::vector<mcc::Symbol>> init_declarator_list;
%type <std::string> "identifier" assignment_operator;
%type <mcc::Symbol> primary_expression;
%type <mcc::Symbol> postfix_expression
%type <mcc::Symbol> expression;
%type <mcc::Symbol> "literal";
%type <mcc::Symbol> "constant";
%type <mcc::T> declaration_specifiers;
%type <mcc::T> type_specifier;
%type <mcc::T> enum_specifier
%type <std::string> unary_operator relational_operator equality_operator;
%type <mcc::Symbol> cast_expression multiplicative_expression additive_expression;
%type <mcc::Symbol> shift_expression relational_expression equality_expression;
%type <mcc::Symbol> bitwise_and_expression bitwise_or_expression constant_expression
%type <mcc::Symbol> bitwise_xor_expression logical_and_expression logical_or_expression
%type <mcc::Symbol> conditional_expression assignment_expression unary_expression
%type <mcc::PtrBits> pointer;
%type <std::pair<std::string,mcc::Symbol>> id_or_idptr direct_declarator declarator;
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
				mcc::PrintColored("Use of undeclared identifier "+$1,mcc::TextColor::Error);
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
			$$={{$1.GetType(),$1.GetDeref()},$1.DerefIsConst(),true,true};
					}
		else if(std::holds_alternative<mcc::CArray>($1.GetType()))
		{
			auto arr_t = std::get<mcc::CArray>($1.GetType());
			auto deref_t = arr_t.GetDerefT();
			$$={{deref_t},true,true,true};
			mcc::PrintColored(std::to_string($$.IsLvalue()),mcc::TextColor::Error);
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
			if(!$1.IsDefined())
			{
				mcc::PrintColored("Function is declared,but not defined",mcc::TextColor::Warning);
			}
			const auto ftype = std::get<std::shared_ptr<mcc::Func>>($1.GetType());
			auto & fargs = ftype->GetArgs();
			if (fargs.size())
			{
				$$={};
				mcc::PrintColored("Argument count mismatch, function requires " +
				 std::to_string(fargs.size())+" arguments," + " have 0"
				,mcc::TextColor::Error);
			}
			else
			$$={ftype->GetReturnType(),false,true,false};
		}
		else
		{
			mcc::PrintColored("Is not a function",mcc::TextColor::Error);
			$$={};
		}
	}
	| postfix_expression "(" argument_expression_list ")"
	{
		if(mcc::IsFuncPtr($1))
		{
			const auto ftype = std::get<std::shared_ptr<mcc::Func>>($1.GetType());
			auto & fargs = ftype->GetArgs();
			const auto arg_count_eq = fargs.size()==$3.size();
			if (!arg_count_eq)
			{
				$$={};
				mcc::PrintColored("Argument count mismatch, function requires " +
				std::to_string(fargs.size()) + " arguments, " + "have " + std::to_string($3.size())
				,mcc::TextColor::Error);
			}
			else
			{
				if(std::equal(fargs.begin(),fargs.end(),$3.begin(),$3.end(),[](auto&&l,auto&&r)
				{
					return l==r.GetType();
				}))
				$$={ftype->GetReturnType(),false,true,false};
				else {
					$$={};
					mcc::PrintColored("Wrong func arg types",mcc::TextColor::Error);
				}
			}
		}
		else
		{
			mcc::PrintColored("Is not a function",mcc::TextColor::Error);
			$$={};
		}
	}
	| postfix_expression "++"
	{
		if(!$1.IsLvalue())
		{
					mcc::PrintColored("Cannot apply ++ operator to a non-lvalue",mcc::TextColor::Error);
		}

		$$=$1.GetRvalue();
		mcc::PrintColored("Postfix increment",mcc::TextColor::Good);
	}
	| postfix_expression "--"
	{
		if(!$1.IsLvalue())
		{
			mcc::PrintColored("Cannot apply -- operator to a non-lvalue",mcc::TextColor::Error);
		}
		$$=$1.GetRvalue();
		mcc::PrintColored("Postfix decrement",mcc::TextColor::Good);
	}
	;

argument_expression_list
	: assignment_expression
		{$$={};$$.push_back($1);}
	| argument_expression_list "," assignment_expression
	{
		$$=$1;
		$$.push_back($3);
	}
	;

unary_expression
	: postfix_expression
	{
		$$=$1;
	}
	| "++" unary_expression
	{
		if(!$2.IsLvalue())
		{
			mcc::PrintColored("Cannot apply ++ operator to a non-lvalue",mcc::TextColor::Error);
		}
		$$=$2.GetRvalue();
	}
	| "--" unary_expression
	{
		if(!$2.IsLvalue())
		{
			mcc::PrintColored("Cannot apply -- operator to a non-lvalue",mcc::TextColor::Error);
		}
		$$=$2.GetRvalue();
	}
	| unary_operator cast_expression
	{
		const auto sym = $1[0];
		switch(sym)
		{
			case '+':
			case '-':
			case '~':
			if(!($2.EvalsToInt()&&!$2.IsUserType()&&!$2.IsPtr()))
			{
				mcc::PrintColored("Invalid type for operand to unary operator " + ("\""+$1)+"\"",mcc::TextColor::Error);
			}
			$$=$2;
			break;
			case '!':
			if($2.IsUserType())
			{
				mcc::PrintColored("Operand for unary operator \"!\" can't be of a struct or a union type",mcc::TextColor::Error);
			}
			$$=$2;
			break;
			case '*':
			if(!$2.IsPtr())
			{
				mcc::PrintColored("Indirection requires pointer operand",mcc::TextColor::Error);
			}
			$$=$2;
			break;
			case '&':
			if(!$2.IsLvalue())
			{
				mcc::PrintColored("Cannot take address of an rvalue",mcc::TextColor::Error);
			}
			$$=$2.GetPtrTo();
			break;

		}
	}
	| "sizeof" unary_expression
	{$$=mcc::Symbol({mcc::Primitive::ULongLong,0},true,true,false);}
	| "sizeof" "(" type_name ")"
	{$$=mcc::Symbol({mcc::Primitive::ULongLong,0},true,true,false);}

	;

unary_operator
	: "+"
	{$$="+";}
	| "*"
	{$$="*";}
	| "&"
	{$$="&";}
	| "-"
	{$$="-";}
	| "~"
	{$$="~";}
	| "!"
	{$$="!";}
	;

cast_expression
	: unary_expression
	{$$=$1;}
	| "(" type_name ")" cast_expression
	{$$=mcc::Symbol{$2,true,true,false};}
	;
multiplicative_operator:
	"*"{$$="*";}|
	"/"{$$="/";}|
	"%"{$$="%";}
multiplicative_expression
	: cast_expression
	{$$=$1;}
	| multiplicative_expression multiplicative_operator cast_expression
	{
		if(!mcc::AreComparable($1,$3)||$1.IsPtr()||$3.IsPtr())
		{
			mcc::PrintColored("Invalid operands to binary operator \""+$2+"\"",mcc::TextColor::Error);
		}
		$$=$1;
	}
	;
additive_operator:
	"+"{$$="+";}
	|"-"{$$="-";}

additive_expression
	: multiplicative_expression
	{$$=$1;}

	| additive_expression additive_operator multiplicative_expression
	{
		if(!mcc::AreComparable($1,$3))
		{
			mcc::PrintColored("Invalid operands to binary operator \""+$2+"\"",mcc::TextColor::Error);
		}
		$$=$1;
	}
	;

shift_operator:
	"<<"{$$="<<";}
	|">>"{$$=">>";}

shift_expression
	: additive_expression
	{$$=$1;}
	| shift_expression shift_operator additive_expression
	{
		if(!mcc::AreComparable($1,$3)||$1.IsPtr()||$3.IsPtr())
		{
			mcc::PrintColored("Invalid operands to binary operator \""+$2+"\"",mcc::TextColor::Error);
		}
		$$=$1;
	}
	;

relational_operator:
	"<"{$$="<";}
	|">"{$$=">";}
	|"<="{$$="<=";}
	|">="{$$=">=";}
equality_operator:
	"=="{$$="==";}
	|"!="{$$="!=";}

relational_expression
	: shift_expression
	| relational_expression relational_operator shift_expression
	{
		if(!(mcc::AreComparable($1,$3)))
		{
			mcc::PrintColored("Invalid operands for binary " + $2 + " operator",mcc::TextColor::Error);
		}
		$$={{mcc::Primitive::Int,0},true,true,false};
	}
	;

equality_expression
	: relational_expression
	| equality_expression equality_operator relational_expression
	{
		if(!(mcc::AreComparable($1,$3)))
		{
			mcc::PrintColored("Invalid operands for binary " + $2 + " operator",mcc::TextColor::Error);
		}
		$$={{mcc::Primitive::Int,0},true,true,false};
	}

	;

bitwise_and_expression
	: equality_expression
	| bitwise_and_expression "&" equality_expression
	{
		if(!mcc::AreComparable($1,$3)||$1.IsPtr()||$3.IsPtr())
		{
			mcc::PrintColored("Invalid operands for binary bitwise \"&\" operator",mcc::TextColor::Error);
		}
		$$={{mcc::Primitive::Int,0},true,true,false};

	}
	;

bitwise_xor_expression
	: bitwise_and_expression
	{$$=$1;}
	| bitwise_xor_expression "^" bitwise_and_expression
	{
		if(!(mcc::AreComparable($1,$3))||$1.IsPtr()||$3.IsPtr())
		{
			mcc::PrintColored("Invalid operands for binary bitwise \"^\" operator",mcc::TextColor::Error);
		}
		$$={{mcc::Primitive::Int,0},true,true,false};

	}
	;

bitwise_or_expression
	: bitwise_xor_expression
	{$$=$1;}
	| bitwise_or_expression "|" bitwise_xor_expression
	{
		if(!(mcc::AreComparable($1,$3))||$1.IsPtr()||$3.IsPtr())
		{
			mcc::PrintColored("Invalid operands for binary bitwise \"|\" operator",mcc::TextColor::Error);
		}
		$$={{mcc::Primitive::Int,0},true,true,false};

	}
	;

logical_and_expression
	: bitwise_or_expression
	| logical_and_expression "&&" bitwise_or_expression
	{
		if(!(mcc::AreComparable($1,$3)))
		{
			mcc::PrintColored("Invalid operands for binary \"&&\" operator",mcc::TextColor::Error);
		}
		$$={{mcc::Primitive::Int,0},true,true,false};

	}
	;

logical_or_expression
	: logical_and_expression
	{$$=$1;}
	| logical_or_expression "||" logical_and_expression
	{
		if(!(mcc::AreComparable($1,$3)))
		{
			mcc::PrintColored("Invalid operands for binary \"||\" operator",mcc::TextColor::Error);
		}
		$$={{mcc::Primitive::Int,0},true,true,false};

	}
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
	{
		if(!mcc::AreComparable($4,$6))
		{
			mcc::PrintColored("Invalid operand types",mcc::TextColor::Error);
		}
		$$=$1;
	}
//TODO :Check if both expression and conditional_expression have a type and types are
//compactible, i.e. you cant do stuff like this:
//char c =  true?"false":1;
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
		if(!mcc::AreCompactible($1,$4))
		{
			mcc::PrintColored("Invalid operands to binary expression operator",mcc::TextColor::Error);
		}
		else
		{
			switch($3[0])
			{
				case '=':
				break;
				case '+':
				case '-':
				if(!AreComparable($1,$4))
					mcc::PrintColored("Invalid operands to binary expression",mcc::TextColor::Error);
				break;
				default:
				if(!AreComparable($1,$4)||$1.IsPtr()||$4.IsPtr())
					mcc::PrintColored("Invalid operands to binary expression",mcc::TextColor::Error);
				break;
			}
		}
		$$=$1;
	}
	;

assignment_operator
	: "="{$$="=";}
	| "*="{$$="*=";}
	| "/="{$$="/=";}
	| "%="{$$="%=";}
	| "+="{$$="+=";}
	| "-="{$$="-=";}
	| "<<="{$$="<<=";}
	| ">>="{$$=">>=";}
	| "&="{$$="&=";}
	| "^="{$$="^=";}
	| "|="{$$="|=";}
	;

expression
	: assignment_expression
	{$$=mcc::Symbol({$1.GetType(),$1.GetIndLevel()},false,true,true);}
	| expression "," assignment_expression
	{$$=mcc::Symbol({$1.GetType(),$1.GetIndLevel()},false,true,true);}
	;

constant_expression
	: conditional_expression{$$=$1;}
	;
// check current scope
declaration
	: declaration_specifiers ";"
	{}
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
	:"extern"
	| "static"
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
	| enum_specifier{$$={mcc::Primitive::Int};}
	| "typename"
		{
			$$ = drv.GetType($1).value();
		}

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

enum_specifier
	: "enum" "{" enumerator_list "}"
	{
		$$={mcc::Primitive::Int};
		for(auto&&name:$3)
		{
			drv.AddSymbol(name,{{mcc::Primitive::Int},true,true,true});
		}
	}
	| "enum" "identifier" "{" enumerator_list "}"
	{
		$$={mcc::Primitive::Int};
		for(auto&&name:$4)
		{
			drv.AddSymbol(name,{{mcc::Primitive::Int},true,true,true});
		}
		if(drv.GetType("enum "+$2))
		{
			mcc::PrintColored("Redefinition of Enumeration "+$2,mcc::TextColor::Error);
		}
		else
		{
			drv.AddTypeAlias("int","enum "+$2);
		}
	}

	| "enum" "identifier"
	{
		$$={mcc::Primitive::Int};
		if(!drv.GetType("enum "+$2))
		{
			mcc::PrintColored("Enumeration "+$2+" is not defined",mcc::TextColor::Error);
		}
	}
	;

enumerator_list
	: enumerator
	{
		$$={};
		$$.push_back($1);
	}
	| enumerator_list "," enumerator
	{
		$$=$1;
		$$.push_back($3);
	}
	;

enumerator
	: "identifier"
	{
		if(drv.GetSymbol($1))
		{
			mcc::PrintColored("Redefinition of identifier "+$1,mcc::TextColor::Error);
		}
	}
	| "identifier" "=" constant_expression
	{
		if(drv.GetSymbol($1))
		{
			mcc::PrintColored("Redefinition of identifier "+$1,mcc::TextColor::Error);
		}
	}

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
		$$=$1;
	}
	//return array of direct_declarator
	| id_or_idptr array_dim_list
	{
		auto as_arr_t = mcc::T{$1.second.GetType()}.ToArrT();
		drv.AddSymbol($1.first,{{mcc::CArray{as_arr_t,$2.begin(),$2.end()},$1.second.GetIndLevel()},drv.GetInConst(),true,false});
		mcc::PrintColored("Array:",mcc::TextColor::Good);
		$$={$1.first,{{mcc::CArray{as_arr_t,$2.begin(),$2.end()},$1.second.GetIndLevel()},drv.GetInConst(),true,false}};
	}
	| id_or_idptr "(" parameter_type_list  ")"
	{
		std::vector<mcc::T> param_types;
		std::transform($3.begin(),$3.end(),std::back_inserter(param_types),[](auto&&arg)
			{
				return arg.second.GetType();
			});
		std::vector<std::string > param_names;
		std::transform($3.begin(),$3.end(),std::back_inserter(param_names),[](auto&&arg)
			{
				return arg.first;
			});
		std::vector<bool > consts;
		std::transform($3.begin(),$3.end(),std::back_inserter(consts),[](auto&&arg)
			{
				return arg.second.IsConst();
			});

		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
		$$={$1.first,{{std::make_shared<mcc::Func>(param_types,param_names,consts),0},drv.GetInConst(),false,false}};
	}
	| id_or_idptr "(" ")"
	{
		mcc::PrintColored("Func argnames",mcc::TextColor::Good);
		$$={$1.first,{{std::make_shared<mcc::Func>(std::vector<mcc::T>{},std::vector<std::string>{},std::vector<bool>{}),0},drv.GetInConst(),true,false}};
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
	{$$=$1;
	$$.push_back($3[0]);}
	;

parameter_declaration
	: declaration_specifiers declarator
	{
			auto decl = $2.second;
			$$={};
			$$.push_back({$2.first,{$1,drv.GetInConst(),true,true}});
	}
	;


type_name
	: specifier_qualifier_list
	{
		$$=$1;
	}
	| specifier_qualifier_list
	{
		drv.SetCurrentCastType($1);
	}
	abstract_declarator
	{
		$$=drv.GetCurrentCastType();
	}
	;

abstract_declarator
	: pointer
	{
		auto cur_t = drv.GetCurrentCastType().GetType();
		drv.SetCurrentCastType({cur_t,$1});
	}
	| direct_abstract_declarator
	| pointer
	{
		auto cur_t = drv.GetCurrentCastType().GetType();
		drv.SetCurrentCastType({cur_t,$1});
	}
	direct_abstract_declarator

	;

direct_abstract_declarator
	: "(" abstract_declarator ")"
	| "[" "]"
	{
		auto arr_t = drv.GetCurrentCastType().ToArrT();
		std::vector<std::size_t> szs;
		szs.push_back(0);
		drv.SetCurrentCastType({mcc::CArray{arr_t,szs.begin(),szs.end()},{}});
	}
	| "[" constant_expression "]"
	{
		auto arr_t = drv.GetCurrentCastType().ToArrT();
		std::vector<std::size_t> szs;
		szs.push_back(0);
		drv.SetCurrentCastType({mcc::CArray{arr_t,szs.begin(),szs.end()},{}});
	}
	| "(" ")"
	| "(" parameter_type_list ")"
	{
		//Return function which has no return type
	}
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
	| "case" constant_expression":"
	{
		if(!IsIntegerT($2.GetType()))
			mcc::PrintColored("Case constant has type which is incompactible with condition type",mcc::TextColor::Error);
	}
	statement
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
//can't print if error in time
selection_statement
	: "if" "(" expression  ")" statement %prec "if"
	| "if" "(" expression ")"
	statement "else" statement
	| "switch" "(" expression ")"
	{
		const auto expr_t = $3.GetType();
		if(!mcc::IsIntegerT(expr_t))
		{
			mcc::PrintColored("Statement requires expression of integer type",mcc::TextColor::Error);
		}
		drv.SetCurrentSwitchType($3.GetType());
	}
	statement
	{
		drv.UnsetCurrentSwitchType();
	}
	;
new_scope_subroutine:
		%empty {drv.EnterNewScope("");}
iteration_statement
	: "while" new_scope_subroutine "(" expression
		{
			if(!$4.EvalsToInt())
				mcc::PrintColored("Statement requires expression of scalar type",mcc::TextColor::Error);
		}
		")" statement
	| "do" new_scope_subroutine statement "while" "(" expression
		{
			if(!$6.EvalsToInt())
				mcc::PrintColored("Statement requires expression of scalar type",mcc::TextColor::Error);
		}
 ")" ";"
	| "for" new_scope_subroutine "(" expression_statement expression_statement ")" statement
	{drv.LeaveScope();}

	| "for" new_scope_subroutine "(" expression_statement expression_statement expression ")" statement
	{drv.LeaveScope();}
	;

jump_statement
	: "goto" "identifier" ";"
	{
		drv.AddLabelRef($2);
	}
	| "continue" ";"
	| "break" ";"
	| "return" ";"
	{
	  const auto ret_t = drv.GetCurrentFuncReturnType();
		if(!ret_t.IsVoid())
		{
			auto scope_name = drv.GetCurrentScope();
			scope_name = scope_name.substr(0,scope_name.find(":"));
			mcc::PrintColored("Non-void function "+scope_name+" should return a value",mcc::TextColor::Error);
		}
	}
	| "return" expression ";"
	{
		const auto ret_t = drv.GetCurrentFuncReturnType();
		const auto phony_symbol = mcc::Symbol{ret_t,true,true,true};
		if(!mcc::AreCompactible(phony_symbol,$2))
		{
			mcc::PrintColored("Return value type incompactible with function return type",mcc::TextColor::Error);
		}
	}
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
	 declaration_specifiers direct_declarator
		{
			if(mcc::IsFuncPtr($2.second))
			{
				auto func = std::get<std::shared_ptr<mcc::Func>>($2.second.GetType());
				func->SetReturnType($1);
				drv.AddSymbol($2.first,{{func,0},drv.GetInConst(),true,false});
				drv.SetCurrentFuncReturnType($1);
				drv.EnterNewScope($2.first);
				for(auto&& [name,type,constness]  : func->GetParams())
				{
					drv.AddSymbol(name,{type,constness,true,true});
				}
			}
			else
			{
				mcc::PrintColored("Is not a valid function declaration",mcc::TextColor::Error);
			}
		}
		compound_statement
		{
					drv.LeaveScope();
		}
	| direct_declarator
		{
			if(mcc::IsFuncPtr($1.second))
			{
				drv.EnterNewScope($1.first);
			}
			else
			{
				mcc::PrintColored("Is not a valid function declaration",mcc::TextColor::Error);
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
