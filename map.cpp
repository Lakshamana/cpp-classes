#include <iostream>
#include <map>

using namespace std;

template <class t, class u>
void print(map<t, u>& map) {
  for (pair<t, u> p : map) {
    cout << p.first << ": " << p.second << endl;
  }
}

int main(int argc, char *argv[]) {

  /*
  * Could be initialized as
  * pair<string, int> pairs[] = {
  *   make_pair("John Doe", 1),
  *   make_pair("Mary Jane", 2),
  *   make_pair("Katy Strong", 3)
  * }
  *
  * // Init passing [start, end[
  * map<string, int> m(pairs, pairs + 3)
  * */

  map<string, int> m = {
    {"John Doe", 1},
    {"Mary Jane", 2},
    make_pair("Katy Strong", 3)
  };

  m.at("John Doe") = 10;
  m["John Doe"] = 1;
  m["Vishal Pradit"] = 4;
  print(m);
  cout << m["John Smith"] << endl;
  cout << m["John Doe"] << endl;
  cout << "Is m empty? " << m.empty() << endl;
  return 0;
}
