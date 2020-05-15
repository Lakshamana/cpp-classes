#include <iostream>

namespace ns1 {
  int n = 50;
}

namespace ns2 {
  int n = 100;
}

using namespace ns1;
using namespace ns2;

int main(int argc, char *argv[]) {
  std::cout << ns1::n << " " << ns2::n << std::endl;
  return 0;
}
