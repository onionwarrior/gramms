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
%left PLUS MINUS
%left MUL DIV
%right POW
%code {
# include "driver.h"
}
%%
file_cont: polynomial END {std::cout<<$1.to_string();}

polynomial:
			 polynomial "+" polynomial
				{ $$=$1+$3; }
			| polynomial "-" polynomial
				{ $$=$1-$3; }
			| polynomial "*" polynomial
				{ $$ = $1*$3; }
			|"(" polynomial ")"
				{ $$ = $2; }
			| polynomial "/" polynomial
				{ $$ =$1/$3;}
			| polynomial "^" "int"
			        { $$=$1^$3;}
                        | monom
                                { $$=$1;}

monom:
			"int" "x" "^" "int"
                                {$$={$1,$4};}
                        |"int" "x"
                                {$$={$1,1};}
                        |"x" "^" "int"
                                {$$={1,$3};}
                        |"x"
                                {$$={1,1};}
                        |"int"
                                {$$={$1,0};}


%%
void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
