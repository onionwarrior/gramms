%language "c++"
%require "3.2"
%code requires{
#include "poly.h"
#include <variant>
}
%define api.pure full
%define api.value.type {std::variant<int64_t,Polynomial>}
%token INTEGER
%token PLUS MINUS MUL DIV POW
%token LEFT RIGHT
%token END

%left PLUS MINUS
%left MUL DIV
%right POW

%%

poly:
			| poly PLUS poly
				{ $$=std::get<Polynomial>($1)+std::get<Polynomial>($3); }
			| poly MINUS poly
				{ $$=std::get<Polynomial>($1)-std::get<Polynomial>($3); }
			| poly MUL poly
				{ $$ = std::get<Polynomial>($1)*std::get<Polynomial>($3); }
			| '-' poly %prec MINUS
				{ $$ = -std::get<Polynomial>($2); }
			| LEFT poly RIGHT
				{ $$ = std::get<Polynomial>($2); }
			| poly DIV poly
				{ $$ = std::get<Polynomial>($1)/std::get<Polynomial>($2);}
			| poly POW INTEGER
			        { $$=std::get<Polynomial>($1)^std::get<int64_t>($3);}
                        | monom
                                { $$=std::get<int64_t>($1);}

monom:
                        |INTEGER 'x' POW INTEGER
                                {$$=Polynomial(std::get<int64_t>($1),std::get<int64_t>($4));}
                        |INTEGER 'x'
                                {$$=Polynomial(std::get<int64_t>($1),1);}
                        |'x' POW INTEGER
                                {$$=Polynomial(1,std::get<int64_t>($3));}
                        |'x'
                                {$$=Polynomial(1,1);}
                        |INTEGER
                                {$$=Polynomial(std::get<int64_t>($1),0);}


%%
