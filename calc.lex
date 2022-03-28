%{
#include "calc.tab.hh"
#include <string>
%}
/*
*Any amount of tabs or spaces counts as newline:
\*****************/
%option noyywrap c++
%option bison-bridge bison-locations
%%

[ \t]+ { }
[[:digit:]]+ {yylval->emplace<int64_t>(std::stoll(yytext));return yy::parser::token::INTEGER;}
"+" return yy::parser::token::PLUS;
"-" return yy::parser::token::MINUS;
"*" return yy::parser::token::MUL;
"/" return yy::parser::token::DIV;
"^" return yy::parser::token::POW;
"(" return yy::parser::token::LEFT;
")" return yy::parser::token::RIGHT;
"\n" return yy::parser::token::END;
