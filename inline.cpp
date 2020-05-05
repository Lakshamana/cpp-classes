#include <iostream>

using namespace std;

// Overrides function calls with its impl
// Use wisely, it can optimize execution time,
// despite increase program disk space amount,
// However most modern computers dismiss this feature
// due their great computational power
inline void foo() {
  cout << "Learning C++ =)" << endl;
}

int main(int argc, char *argv[]) {
  foo();
  return 0;
}
