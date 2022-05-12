%{
#include <string>
#include <cstring>
#include "driver.h"
#include "mcc_c.tab.h"
%}

%option noyywrap nounput noinput batch debug
  // A number symbol corresponding to the value in S.
%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%x IN_COMMENT
decimal			[0-9]
letter			[a-zA-Z_]
hex			[a-fA-F0-9]
oct			[0-7]
exp			[Ee][+-]?{decimal}+
fs			(f|F|l|L)
sgn			(u|U|l|L)*

%{
void count();
yy::parser::symbol_type check_type(const std::string & s,const yy::parser::location_type &loc);
yy::parser::symbol_type make_IDENTIFIER(const std::string & s,const yy::parser::location_type &loc);
%}

%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}
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
"goto"			{ count(); return yy::parser::make_GOTO(loc); }
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

{letter}({letter}|{decimal})*		{ count(); return check_type(yytext,loc); }

0[xX]{hex}+{sgn}?		{ count(); return yy::parser::make_CONSTANT(loc); }
0{decimal}+{sgn}?		{ count(); return yy::parser::make_CONSTANT(loc); }
{decimal}+{sgn}?		{ count(); return yy::parser::make_CONSTANT(loc); }
L?'(\\.|[^\\'])+'	{ count(); return yy::parser::make_CONSTANT(loc); }

{decimal}+{exp}{fs}?		{ count(); return yy::parser::make_CONSTANT(loc); }
{decimal}*"."{decimal}+({exp})?{fs}?	{ count(); return yy::parser::make_CONSTANT(loc); }
{decimal}+"."{decimal}*({exp})?{fs}?	{ count(); return yy::parser::make_CONSTANT(loc); }

L?\"(\\.|[^\\"])*\"	{ count(); return yy::parser::make_STRING_LITERAL(loc); }

"..."			{ count(); return yy::parser::make_ELLIPSIS(loc); }
">>="			{ count(); return yy::parser::make_RIGHT_ASSIGN(loc); }
"<<="			{ count(); return yy::parser::make_LEFT_ASSIGN(loc); }
"+="			{ count(); return yy::parser::make_ADD_ASSIGN(loc); }
"-="			{ count(); return yy::parser::make_SUB_ASSIGN(loc); }
"*="			{ count(); return yy::parser::make_MUL_ASSIGN(loc); }
	yy::location& loc = drv.location;
"/="			{ count(); return yy::parser::make_DIV_ASSIGN(loc); }
"%="			{ count(); return yy::parser::make_MOD_ASSIGN(loc); }
"&="			{ count(); return yy::parser::make_AND_ASSIGN(loc); }
"^="			{ count(); return yy::parser::make_XOR_ASSIGN(loc); }
"|="			{ count(); return yy::parser::make_OR_ASSIGN(loc); }
">>"			{ count(); return yy::parser::make_SHR(loc); }
"<<"			{ count(); return yy::parser::make_SHL(loc); }
"++"			{ count(); return yy::parser::make_INC(loc); }
"--"			{ count(); return yy::parser::make_DEC(loc); }
"->"			{ count(); return yy::parser::make_PTR(loc); }
"&&"			{ count(); return yy::parser::make_LAND(loc); }
"||"			{ count(); return yy::parser::make_LOR(loc); }
"<="			{ count(); return yy::parser::make_LEQ(loc); }
">="			{ count(); return yy::parser::make_GEQ(loc); }
"=="			{ count(); return yy::parser::make_EQ(loc); }
"!="			{ count(); return yy::parser::make_NEQ(loc); }
";"			{ count(); return yy::parser::make_SEMI(loc); }
("{"|"<%")		{ count(); return yy::parser::make_L_CURLY(loc); }
("}"|"%>")		{ count(); return yy::parser::make_R_CURLY(loc); }
","			{ count(); return yy::parser::make_COMMA(loc); }
":"			{ count(); return yy::parser::make_COL(loc); }
"="			{ count(); return yy::parser::make_ASS(loc); }
"("			{ count(); return yy::parser::make_LEFT_PAR(loc); }
")"			{ count(); return yy::parser::make_RIGHT_PAR(loc); }
("["|"<:")		{ count(); return yy::parser::make_L_SQBR(loc); }
("]"|":>")		{ count(); return yy::parser::make_R_SQBR(loc); }
"."			{ count(); return yy::parser::make_DOT(loc); }
"&"			{ count(); return yy::parser::make_AND(loc); }
"!"			{ count(); return yy::parser::make_NOT(loc); }
"~"			{ count(); return yy::parser::make_FLIP(loc); }
"-"			{ count(); return yy::parser::make_MINUS(loc); }
"+"			{ count(); return yy::parser::make_PLUS(loc); }
"*"			{ count(); return yy::parser::make_MUL(loc); }
"/"			{ count(); return yy::parser::make_DIV(loc); }
"%"			{ count(); return yy::parser::make_MOD(loc); }
"<"			{ count(); return yy::parser::make_LE(loc); }
">"			{ count(); return yy::parser::make_GE(loc); }
"^"			{ count(); return yy::parser::make_XOR(loc); }
"|"			{ count(); return yy::parser::make_OR(loc); }
"?"			{ count(); return yy::parser::make_Q_MARK(loc); }
\n			{ count();loc.lines(); }
[ \t\v\n\f]		{ count(); }
.			{ /* ignore bad characters */ }
<<EOF>> return yy::parser::make_END(loc);
%%




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


yy::parser::symbol_type check_type(const std::string & s,const yy::parser::location_type  & loc)
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
	return make_IDENTIFIER(s,loc);
}
yy::parser::symbol_type make_IDENTIFIER(const std::string & s, const yy::parser::location_type &loc)
{
  return yy::parser::make_IDENTIFIER(s,loc);
}
void
driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror (errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void
driver::scan_end ()
{
  fclose (yyin);
}

