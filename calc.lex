%{
#include <string>
#include <cstring>
#include "driver.h"
#include "calc.tab.h"
%}

%option noyywrap nounput noinput batch debug
%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type
  make_INTEGER (const std::string &s, const yy::parser::location_type& loc);
  yy::parser::symbol_type
  make_BASIC (const std::string &s, const yy::parser::location_type& loc);
  yy::parser::symbol_type
  make_VAR (const std::string &s, const yy::parser::location_type& loc);


%}
%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
var_ref_or_decl \@[a-zA-Z][a-zA-Z0-9_]+
var_basic [a-z]
%x IN_COMMENT
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
{var_ref_or_decl} return make_VAR(yytext,loc);
{var_basic} return make_BASIC(yytext,loc);
[ \t\r]+
"+" return yy::parser::make_PLUS(loc);
"-" return yy::parser::make_MINUS(loc);
"*" return yy::parser::make_MUL(loc);
"/" return yy::parser::make_DIV(loc);
"^" return yy::parser::make_POW(loc);
":=" return yy::parser::make_DECL(loc);
[[:digit:]]+ return make_INTEGER(yytext,loc);
"(" return yy::parser::make_LEFT(loc);
")" return yy::parser::make_RIGHT(loc);
"<<" return yy::parser::make_PRINT(loc);
\n  { loc.lines();return yy::parser::make_NL(loc);}
<<EOF>> return yy::parser::make_END(loc);
%%
yy::parser::symbol_type
make_INTEGER (const std::string &s, const yy::parser::location_type& loc)
{
  errno = 0;
  const int64_t n = std::stoll(s.c_str());
  return yy::parser::make_INTEGER ( n, loc);
}
yy::parser::symbol_type
  make_VAR (const std::string &s, const yy::parser::location_type& loc)
{
  errno =0;
  const auto var_name = s.substr(1);
  return yy::parser::make_VAR(var_name,loc);
}
yy::parser::symbol_type
  make_BASIC (const std::string &s, const yy::parser::location_type& loc)
{
  errno =0;
  const auto var_name = s[0];
  return yy::parser::make_BASIC(var_name,loc);
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
