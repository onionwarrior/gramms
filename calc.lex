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
%}
%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}
[ \t\r]+
"+" return yy::parser::make_PLUS(loc);
"-" return yy::parser::make_MINUS(loc);
"*" return yy::parser::make_MUL(loc);
"/" return yy::parser::make_DIV(loc);
"^" return yy::parser::make_POW(loc);
-?[[:digit:]]+ return make_INTEGER(yytext,loc);
"(" return yy::parser::make_LEFT(loc);
")" return yy::parser::make_RIGHT(loc);
"x" return yy::parser::make_VAR(loc);
\n return yy::parser::make_NL(loc);
<<EOF>> return yy::parser::make_END(loc);
%%
yy::parser::symbol_type
make_INTEGER (const std::string &s, const yy::parser::location_type& loc)
{
  errno = 0;
  const int64_t n = std::stoll(s.c_str());
  return yy::parser::make_INTEGER ( n, loc);
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
