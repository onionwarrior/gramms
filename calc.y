%skeleton "lalr1.cc"
%require "3.8.1"
%code requires{
#include <sstream>
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
%token <std::string> VAR "var";
%token <char> BASIC "basic";
%token
	NL "\n"
	PLUS "+"
	MINUS "-"
	MUL "*"
	DIV "/"
	POW "^"
	LEFT "("
	RIGHT ")"
	DECL ":="
	PRINT "<<"
	;
%token END 0 "end of file"
%param { driver& drv }
%type <Polynomial> polynomial monom any_var;
%type <int64_t> pow;
/*Everything is printed using <<*/
%printer { yyo << $$; } <*>;
%left PLUS MINUS
%left MUL DIV
%left UMINUS
%right POW
%code {
# include "driver.h"
}
%%

calculation:
			line {}
			| calculation line{}

line:
			"var" ":=" polynomial "\n"
				{SymbolTable::GetInst()->GetVar($1)=$3;}
			| "<<" "var" "\n"
				{
				const auto variable = SymbolTable::GetInst()->ReadVar($2);
				if (!variable)
				{
					std::stringstream cause{};
					cause<<"'<< "<<$2<<"' at "<<drv.location;
					throw std::invalid_argument("No such variable, caused by: "+cause.str());
				}
				std::cout<<variable.value()<<std::endl;
				}
			| "\n"
polynomial:
			monom /*A single monom*/
				{ $$=$1;}
			| "-" polynomial %prec UMINUS /* Inverted polynomial*/
				{$$=-$2;}
			| polynomial "+" polynomial
				{
						const auto br=$1.GetBase();
						const auto bl=$3.GetBase();
						if(br!=bl&&bl&&br)
						{
								std::stringstream cause{};
								cause<<"'Cant add "<<$1<<" and "<<$3<<"' at "<<drv.location;
								throw std::invalid_argument("Base mismatch, caused by: "+cause.str());
						}
						$$=$1+$3;
						$$.SetBase((std::max)(br,bl));
				}
			| polynomial "-" polynomial
				{
						const auto br=$1.GetBase();
						const auto bl=$3.GetBase();
						if(br!=bl&&bl&&br)
						{
								std::stringstream cause{};
								cause<<"'Cant sub "<<$3<<" from "<<$1<<"' at "<<drv.location;
								throw std::invalid_argument("Base mismatch, caused by: "+cause.str());
						}
						$$=$1-$3;
						$$.SetBase((std::max)(br,bl));
				}
			| polynomial "*" polynomial
				{
						const auto br=$1.GetBase();
						const auto bl=$3.GetBase();
						if(br!=bl&&bl&&br)
						{
								std::stringstream cause{};
								cause<<"'Cant multiply "<<$1<<" by "<<$3<<"' at "<<drv.location;
								throw std::invalid_argument("Base mismatch, caused by: "+cause.str());
						}
						$$ = $1*$3;
						$$.SetBase((std::max)(br,bl));
				}
			|"(" polynomial ")" /*Brace support*/
				{ $$ = $2; }
			| polynomial "/" polynomial
				{
						const auto br=$1.GetBase();
						const auto bl=$3.GetBase();
						if(br!=bl&&bl&&br)
						{
								std::stringstream cause{};
								cause<<"'Cant divide "<<$1<<" by "<<$3<<"' at "<<drv.location;
								throw std::invalid_argument("Base mismatch, caused by: "+cause.str());
						}
						if($3.degree()==0)
						{
								std::stringstream cause{};
								cause<<"'Cant divide "<<$1<<" by "<<"zero"<<"' at "<<drv.location;
								throw std::invalid_argument("Division by zero, caused by: "+cause.str());
						}
						$$ =$1/$3;
						$$.SetBase((std::max)(br,bl));
				}
			| "(" polynomial ")" "^" polynomial
				/*Raising a polynomial to a certain power
				 * requires enclosing it with brackets*/
			        {
					const auto deg = $2.degree();
					if(deg!=0)
					{
						std::stringstream cause{};
						cause<<"'("<<$2<<")^"<<"("<<$5<<")' at "<<drv.location;
						throw std::invalid_argument("Raising to negative power is forbiden, caused by: "+cause.str());
					}
					const auto coef = $5.lead().coef();
					if(coef<0)
					{
						std::stringstream cause{};
						cause<<"'("<<$2<<")^"<<"("<<$5<<")' at "<<drv.location;
						throw std::invalid_argument("Raising to negative power is forbiden, caused by: "+cause.str());
					}
					$$=$2^coef;
				}

monom:
			/*All possible ways to represent a monom*/
			"int" any_var "^" pow
				{$$=($2^$4)*Polynomial{$1,0,0};}
			|any_var "^" pow
				{$$=$1^$3;}
			|"int" any_var
                {$$=Polynomial{$1,0,0}*$2;}
		    |any_var
				{$$=$1;}
		    |"int"
				{$$={$1,0,0};}
pow:
		"int"
		{$$=$1;}
		| "(" pow ")"
		{$$=$2;}
		| pow "^" pow
		{$$=ipow64($1,$3);}
any_var:
		"basic"
		{$$={1,1,$1};}
		| "var"
		{
					auto var = SymbolTable::GetInst()->ReadVar($1);
					if (!var)
					{
						std::stringstream cause{};
						cause<<"'"<<$1<<"' at "<<drv.location;
						throw std::invalid_argument("No such variable, caused by: "+cause.str());
					}
				    $$=var.value();
		};


%%
void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
