%skeleton "lalr1.cc"
%require "3.8.1"
%code requires{
#include <stdio.h>
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
%type <std::vector<std::string>> identifier_list
%type <std::string> declarator;
%type <mcc::Symbol> primary_expression;
%type <mcc::Symbol> postfix_expression
%type <mcc::Symbol> expression
%type <mcc::Symbol> "literal"
%type <mcc::Symbol> "constant"
%type <mcc::type_t> declaration_specifiers;
%type <mcc::type_t> type_specifier;
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

			}
			else
			{
				$$={};
			mcc::PrintColored("No such identifier: "+drv.GetCurrentScope()+$1,mcc::TextColor::Error);
			drv.DumpSymbols();
			}
		}
	}
	| "constant"
	{
		mcc::PrintColored("Numeric const",mcc::TextColor::Good);
		$$={mcc::Primitive::Int,0,true,true,true};
	}
	| "literal"
	{
		mcc::PrintColored("String literal",mcc::TextColor::Good);
		$$={mcc::Primitive::Char,1,true,true,true};
	}
	| "(" expression ")"
	{
	$$=$1;
	}
	;

postfix_expression
	: primary_expression
	| postfix_expression "[" expression "]"
	{
		mcc::PrintColored("Array or ptr subscript operation",mcc::TextColor::Good);
		const auto is_sub_int = mcc::IsIntegerT($3.GetType());
		const auto ind = $3.GetType().index();
		mcc::PrintColored(std::to_string(ind),mcc::TextColor::Error);
		if( $1.IsPtr())
		{
			if(!is_sub_int && !$3.IsPtr())
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
	| "++" unary_expression
	| "--" unary_expression
	| unary_operator cast_expression
	| "sizeof" unary_expression
	| "sizeof" "(" type_name ")"
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
	| "(" type_name ")" cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression "*" cast_expression
	| multiplicative_expression "/" cast_expression
	| multiplicative_expression "%" cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression "+" multiplicative_expression
	| additive_expression "-" multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression "<<" additive_expression
	| shift_expression ">>" additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression "<=" shift_expression
	| relational_expression ">=" shift_expression
	| relational_expression "<" shift_expression
	| relational_expression ">" shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression "==" relational_expression
	| equality_expression "!=" relational_expression
	;

and_expression
	: equality_expression
	| and_expression "&" equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression "^" and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression "|" exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression "||" inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression "&&" logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression "?" expression ":" conditional_expression
	;

assignment_expression
	: conditional_expression
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
		mcc::PrintColored("New decl "+$1,mcc::TextColor::Good);
		mcc::PrintColored("Type "+std::string(std::holds_alternative<mcc::Primitive>(drv.GetCurrentType())?"primitive":"amogus"),mcc::TextColor::Good);
		auto sym = mcc::Symbol{drv.GetCurrentType(),0,false,true,true};
		drv.AddSymbol($1,std::move(sym));
	}
	| declarator "=" initializer
	{
		mcc::PrintColored("Type "+std::string(std::holds_alternative<mcc::Primitive>(drv.GetCurrentType())?"primitive":"amogus"),mcc::TextColor::Good);
		mcc::PrintColored("New decl "+$1,mcc::TextColor::Good);
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
	: "void"
	{$$=mcc::Primitive::Void;}
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
	| "typename"{}
	;

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
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
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
	: "const"{drv.SetInConst(true);}
	| "volatile"{}
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
	}

	| direct_declarator "(" parameter_type_list ")"
	| direct_declarator "(" identifier_list  ")"
	{
	mcc::PrintColored("Function call:" +$1,mcc::TextColor::Good);
	}
	| direct_declarator "(" ")"
	;

pointer
	: "*"
	| "*" type_qualifier_list
	| "*" pointer
	| "*" type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
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
	{
		 $$={};
		 $$.push_back($1);
		 mcc::PrintColored("Id"+$1,mcc::TextColor::Good);
	}
	| identifier_list "," "identifier"
	{
		$1.emplace_back($3);
		$$=std::move($1);
		for(auto && id : $$)
		{
			mcc::PrintColored("Id:"+id,mcc::TextColor::Good);
		}
	}
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
	: "while" "(" expression ")" statement
	| "do" statement "while" "(" expression ")" ";"
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
	: declaration_specifiers declarator declaration_list {mcc::PrintColored("Entered new scope: "+ $2,mcc::TextColor::Good);drv.EnterNewScope($2);} compound_statement
		{drv.LeaveScope();}
	| declaration_specifiers declarator {mcc::PrintColored("Entered new scope: "+$2,mcc::TextColor::Good);drv.EnterNewScope($2);} compound_statement
		{drv.LeaveScope();}
	| declarator declaration_list {mcc::PrintColored("Entered new scope: "+$1,mcc::TextColor::Good);drv.EnterNewScope($1);} compound_statement
		{drv.LeaveScope();}
	| declarator {mcc::PrintColored("Entered new scope"+$1,mcc::TextColor::Good);drv.EnterNewScope($1);} compound_statement
	{drv.LeaveScope();}
	;

%%
void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
