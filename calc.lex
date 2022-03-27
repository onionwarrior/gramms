%{
#include "calc.tab.hh"
#include <string>
%}
/*
*Any amount of tabs or spaces counts as newline:
\*****************/

%%

[ \t]+ { }
[[:digit:]]+ return std::stoll(yytext);
"+" return PLUS;
"-" return MINUS;
"*" return MUL;
"/" return DIV;
"^" return POW;
"(" return LEFT;
")" return RIGHT;
"\n" return END;
