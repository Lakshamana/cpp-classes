#include <iostream>
#include <list>

using namespace std;

// function condition
bool even(int n) {
  return n % 2 == 0;
}

bool cmp(string& s1, string& s2) {
  return s1.length() < s2.length();
}

// You can have template function as well as classes too
// By default it is int type
template <typename t = int> void printl(list<t>& l, const char* end = " ") {
  if (l.empty()) {
    cout << "--empty--\n" << endl;
    return;
  }
  for (t item : l) {
    cout << item << end;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  list<int> l1(2, 10), l2(2, 20);

  // Sends l2 elements to l1's tail, modifying l2
  l1.splice(l1.end(), l2);

  cout << "l1 content:" << endl;
  printl(l1);
  cout << "\nl2 content:" << endl;
  printl(l2);

  // Removes all elements equal a value
  l1.remove(20);
  cout << "l1 content after removing all 20s:" << endl;
  printl(l1);

  // Removes items matching a condition
  int v[] = {4, 3, 87, 12, 6, 76, 15, 45};
  int *final = v + sizeof(v) / sizeof(int);
  list<int> l3(v, final);
  printl(l3);

  l3.remove_if(even);
  cout << "\nl3 content after removing all even numbers:" << endl;
  printl(l3);

  l3.assign(v, final);
  l3.sort();
  cout << "\nsorted l3:" << endl;
  printl(l3);

  // Sort by criteria
  string s[] = {"zzz", "A* pathfinding", "bfs algo", "dijkstra"};
  list<string> names;
  names.assign(s, s + 4);
  names.sort(cmp);
  cout << "\nsorted names:" << endl;
  printl<string>(names, "\n");
  return 0;
}
