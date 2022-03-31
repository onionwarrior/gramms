%skeleton "lalr1.cc"
%require "3.8.1"
%code requires{
#include "poly.h"
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

%token <int64_t> INTEGER "int";
%token
	NL "\n"
	PLUS "+"
	MINUS "-"
	MUL "*"
	DIV "/"
	POW "^"
	LEFT "("
	RIGHT ")"
	VAR "x"
	;
%token END 0 "end of file"
%param { driver& drv }
%type <Polynomial> polynomial;
%type <Monom> monom;
%type <int64_t> integer_const;
%type <int64_t> int_eval;
%printer { yyo << $$; } <*>;
%left PLUS MINUS
%left MUL DIV
%left UMINUS
%right POW
%code {
# include "driver.h"
}
%%
calculation: |calculation line

line: "\n"
    | polynomial NL
		{std::cout<<"Result: "<<$1<<std::endl;}
polynomial:		monom
				{ $$=$1;}
			| "-" polynomial %prec UMINUS
				{$$=-$2;}
			| polynomial "+" polynomial
				{ $$=$1+$3; }
			| polynomial "-" polynomial
				{ $$=$1-$3; }
			| polynomial "*" polynomial
				{ $$ = $1*$3; }
			|"(" polynomial ")"
				{ $$ = $2; }
			| polynomial "/" polynomial
				{ $$ =$1/$3;}
			| "(" polynomial ")" "^" integer_const
			        { $$=$2^$5;}

monom:
			"int" "x" "^" integer_const
				{$$={$1,$4};}
			|"x" "^" integer_const
				{$$={1,$3};}
			|"int" "x"
                                {$$={$1,1};}
                        |"x"
                                {$$={1,1};}
                        |"int"
                                {$$={$1,0};}
			|"int" "^" integer_const
				{$$={ipow64($1,$3),0};}

integer_const:		"int"
				{$$=$1;}
			| "-" "int" %prec UMINUS
				{$$=-$2;}
			| "(" int_eval ")"
				{$$=$2;}

int_eval:		"int"
				{$$=$1;}
			| "-" "int" %prec UMINUS
				{$$=-$2;}
			|"(" int_eval ")"
				{$$=$2;}
			|int_eval "*" int_eval
				{$$=$1*$3;}
			| int_eval "/" int_eval
				{$$=$1/$3;}
			| int_eval "+" int_eval
				{$$=$1+$3;}
			| int_eval "-" int_eval
				{$$=$1-$3;}
			| int_eval "^" int_eval
				{$$=ipow64($1,$3);}
%%
void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
