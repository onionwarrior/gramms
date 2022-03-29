#include "poly.h"
#include <iostream>

int main()
{
  Polynomial poly1{3,7},poly2{3,5};
  auto div = poly1/poly2;
  std::cout<<div.to_string()<<std::endl;
}
