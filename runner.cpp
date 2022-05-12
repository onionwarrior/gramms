#include "driver.h"
#include <iostream>

int main(int argc, char *argv[]) {
  int res = 0;
  driver drv;
  for (int i = 1; i < argc; ++i)
    if (argv[i] == std::string("-p"))
      drv.trace_parsing = true;
    else if (argv[i] == std::string("-s"))
      drv.trace_scanning = true;
    else {
      try {

        res = drv.parse(argv[i]);
      } catch (std::exception &e) {
        std::cout << "\033[31m"
                  << "Error: " << e.what() << "\033[0m"<<std::endl;
      }
    }
  return res;
}
