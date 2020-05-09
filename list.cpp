#include <iostream>
#include <list>

using namespace std;

// s = start, where
// delete range = [start, end[
void deleteRange(list<int>& l, int s, int end) {
  list<int>::iterator it1, it2;
  it1 = it2 = l.begin();
  int i = 0;
  while(i < end) {
    if (i < s) it1++;
    if (i < end) it2++;
    i++;
  }
  l.erase(it1, it2);
}

int main(int argc, char *argv[]) {
  list<int> l1;
  list<int> l2(3, 10); // 3 items with value of 10
  list<int>::iterator it;

  l1.push_back(10);
  l1.push_front(20);
  l1.push_back(30);

  for (it = l1.begin(); it != l1.end(); it++) {
    cout << *it << " ";
  }

  cout << endl;
  for (int i : l2) {
    cout << i << " ";
  }

  cout << "\nl1 first: " << l1.front() << endl;
  cout << "l1 last: " << l1.back() << endl;

  l1.pop_front();
  l1.pop_back();

  cout << "\nl1 content after removing front and back: " << endl;
  for (int i : l1) {
    cout << i << " ";
  }

  while(!l2.empty()) {
    l2.pop_back();
  }

  cout << "\nl2 size after its clearing: " << l2.size() << endl;

  // Assign elements to list
  int v[] = {1, 2, 3, 4, 5};
  l2.assign(v, v + 5); // assign address range: [start, end[

  // in this case end points to the list end element,
  // this list is a set of non-contiguous memory addresses,
  // so doing `l2.insert(l2.end() - 1, 6)` won't compile

  // l2.insert(l2.end() - 1, 6); // compilation error
  // l2.insert(l2.begin() + 1, 100); // compilation error too
  it = l2.begin();
  l2.insert(++it, 2, 100); // insert twice 100 from 2nd position

  cout << "\nl2 content after assign and insert: " << endl;
  for (int i : l2) {
    cout << i << " ";
  }

  cout << "\n\nclearing 2nd & 3rd position elements:" << endl;
  // list<int>::iterator it2 = l2.begin();
  // list<int>::iterator tmp = ++it2;
  // l2.erase(tmp, ++(++it2));
  deleteRange(l2, 1, 3);
  for (int i : l2) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
