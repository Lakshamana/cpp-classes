#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
  int v[] = {10, 40, 10, 40, 20};
  set<int> s(v, v + 5); // remove duplicate and asc-order vector set
  for (int i : s) {
    cout << i << " ";
  }
  cout << endl;

  set<int>::iterator it = s.find(50);
  if (it == s.end()) {
    cout << "Element 50 doesn't exist" << endl;
  } else {
    cout << "Element 50 exists" << endl;
  }
  return 0;
}
