#include "driver.h"
#include "mcc_c.tab.h"
driver::driver()
{

}
int
driver::parse (const std::string &f)
{
  file = f;
  location.initialize (&file);
  scan_begin ();
  yy::parser parse(*this);
  parse.set_debug_level (trace_parsing);
  auto res = parse ();
  scan_end ();
  return res;
}
