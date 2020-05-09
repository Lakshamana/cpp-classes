#include <iostream>

using namespace std;

template<typename t> t sum(t n1, t n2) {
  return n1 + n2;
}

int main(int argc, char *argv[]) {
  cout << sum(10, 40) << endl;
  cout << sum(2.71828, 3.14151) << endl;
  // cout << sum(2, 3.14151) << endl;  compilation error
  return 0;
}
