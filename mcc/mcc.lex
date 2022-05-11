%{
#include <string>
#include <cstring>
#include "driver.h"
#include "mcc_c.tab.h"
%}
decimal			[0-9]
letter			[a-zA-Z_]
hex			[a-fA-F0-9]
oct			[0-7]
exp			[Ee][+-]?{D}+
fs			(f|F|l|L)
sgn			(u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"
void comment();
void count();
int check_type();
%}

%%
^"//".*
<INITIAL>"/*" BEGIN(IN_COMMENT);
<IN_COMMENT>"*/"      BEGIN(INITIAL);
<IN_COMMENT>[^*\n]+   // eat comment in chunks
<IN_COMMENT>"*"       // eat the lone star
<IN_COMMENT>\n loc.lines();
<IN_COMMENT><<EOF>> std::cerr<<"Warning: Could not match /* with */ at "<<loc<<std::endl; BEGIN(INITIAL);

"auto"			{ count(); return yy::parser::make_AUTO(loc); }
"break"			{ count(); return yy::parser::make_BREAK(loc); }
"case"			{ count(); return yy::parser::make_CASE(loc); }
"char"			{ count(); return yy::parser::make_CHAR(loc); }
"const"			{ count(); return yy::parser::make_CONST(loc); }
"continue"		{ count(); return yy::parser::make_CONTINUE(loc); }
"default"		{ count(); return yy::parser::make_DEFAULT(loc); }
"do"			{ count(); return yy::parser::make_DO(loc);  }
"double"		{ count(); return yy::parser::make_DOUBLE(loc); }
"else"			{ count(); return yy::parser::make_ELSE(loc); }
"enum"			{ count(); return yy::parser::make_ENUM(loc); }
"extern"		{ count(); return yy::parser::make_EXTERN(loc); }
"float"			{ count(); return yy::parser::make_FLOAT(loc);}
"for"			{ count(); return yy::parser::make_FOR(loc); }
"goto"			{ count();return yy::parser::make_GOTO(loc); }
"if"			{ count(); return yy::parser::make_IF(loc); }
"int"			{ count(); return yy::parser::make_INT(loc); }
"long"			{ count(); return yy::parser::make_LONG(loc); }
"register"		{ count(); return yy::parser::make_REGISTER(loc); }
"return"		{ count(); return yy::parser::make_RETURN(loc); }
"short"			{ count(); return yy::parser::make_SHORT(loc); }
"signed"		{ count(); return yy::parser::make_SIGNED(loc); }
"sizeof"		{ count(); return yy::parser::make_SIZEOF(loc); }
"static"		{ count(); return yy::parser::make_STATIC(loc); }
"struct"		{ count(); return yy::parser::make_STRUCT(loc); }
"switch"		{ count(); return yy::parser::make_SWITCH(loc); }
"typedef"		{ count(); return yy::parser::make_TYPEDEF(loc); }
"union"			{ count(); return yy::parser::make_UNION(loc); }
"unsigned"		{ count(); return yy::parser::make_UNSIGNED(loc); }
"void"			{ count(); return yy::parser::make_VOID(loc); }
"volatile"		{ count(); return yy::parser::make_VOLATILE(loc); }
"while"			{ count(); return yy::parser::make_WHILE(loc); }

{L}({L}|{D})*		{ count(); return(check_type()); }

0[xX]{H}+{IS}?		{ count(); return(CONSTANT); }
0{D}+{IS}?		{ count(); return(CONSTANT); }
{D}+{IS}?		{ count(); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ count(); return(CONSTANT); }

{D}+{E}{FS}?		{ count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ count(); return(STRING_LITERAL); }

"..."			{ count(); return(ELLIPSIS); }
">>="			{ count(); return(RIGHT_ASSIGN); }
"<<="			{ count(); return(LEFT_ASSIGN); }
"+="			{ count(); return(ADD_ASSIGN); }
"-="			{ count(); return(SUB_ASSIGN); }
"*="			{ count(); return(MUL_ASSIGN); }
"/="			{ count(); return(DIV_ASSIGN); }
"%="			{ count(); return(MOD_ASSIGN); }
"&="			{ count(); return(AND_ASSIGN); }
"^="			{ count(); return(XOR_ASSIGN); }
"|="			{ count(); return(OR_ASSIGN); }
">>"			{ count(); return(RIGHT_OP); }
"<<"			{ count(); return(LEFT_OP); }
"++"			{ count(); return(INC_OP); }
"--"			{ count(); return(DEC_OP); }
"->"			{ count(); return(PTR_OP); }
"&&"			{ count(); return(AND_OP); }
"||"			{ count(); return(OR_OP); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"=="			{ count(); return(EQ_OP); }
"!="			{ count(); return(NE_OP); }
";"			{ count(); return(';'); }
("{"|"<%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","			{ count(); return(','); }
":"			{ count(); return(':'); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."			{ count(); return('.'); }
"&"			{ count(); return('&'); }
"!"			{ count(); return('!'); }
"~"			{ count(); return('~'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"^"			{ count(); return('^'); }
"|"			{ count(); return('|'); }
"?"			{ count(); return('?'); }

[ \t\v\n\f]		{ count(); }
.			{ /* ignore bad characters */ }

%%

int yywrap()
{
	return(1);
}



int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return(TYPE_NAME);
*
*	retrn(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/

	return(IDENTIFIER);
}
