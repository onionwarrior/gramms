#ifndef _DRIVER_H_
#define _DRIVER_H_
#include "calc.tab.h"
#include "location.hh"

#define YY_DECL yy::parser::symbol_type yylex(driver &drv)
YY_DECL;
class driver {
public:
  driver();
  int64_t result = 0;
  int parse(const std::string &f);
  std::string file;
  bool trace_parsing = false;
  void scan_begin();
  void scan_end();
  bool trace_scanning = false;
  yy::location location;
};
#endif
