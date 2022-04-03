#include <cstdio>
#include <iostream>
#include <set>
#include <utility>

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

  set<pair<double, int>> s2 = { make_pair(3.0, 1), make_pair(1.0, 2) };
  cout << "Keys: ";
  for (pair<double, int> pair : s2) {
    printf("%.1f ", pair.first);
  }

  return 0;
}
