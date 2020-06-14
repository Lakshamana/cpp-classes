#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
  multimap<int, string> mm;
  mm.insert(pair<int, string>(1, "python 2"));
  mm.insert(pair<int, string>(1, "python 3"));
  mm.insert(pair<int, string>(2, "C"));
  mm.insert(pair<int, string>(2, "C++"));
  mm.insert(pair<int, string>(3, "Ruby"));

  multimap<int, string>::iterator it = mm.find(1);
  cout << it->first << ": " << it->second << endl; // 1: python 2
  ++it;
  cout << it->first << ": " << it->second << endl << endl; // 1: python 3

  multimap<int, string>::iterator itlow, itup;
  itlow = mm.lower_bound(2);
  itup = mm.upper_bound(3);
  for (it = itlow; it != itup; ++it) {
    printf("%i: %s\n", it->first, it->second.c_str());
  }
  return 0;
}
