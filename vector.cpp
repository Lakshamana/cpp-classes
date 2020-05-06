#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  vector<string> v1;
  v1.push_back("We");
  v1.push_back("were");
  v1.push_back("discovered,");
  v1.push_back("hide");
  v1.push_back("yourself");

  for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << endl;
  }

  vector<int> v2(5);
  int array[] = {1, 4, 2, 7, 8, 3, 0};
  // Be careful to not loop over a vector along its size
  // whilst altering the vector's size.
  // This may cause your program run into a Segmentation Fault!!!
  for (int i = 0; i < v2.size(); i++) {
    v2[i] = array[i];
    // cout << v2[i] << endl;
  }

  // Iterators
  // it is a pointer to each vector element
  vector<int>::iterator it;
  for (it = v2.begin(); it != v2.end(); it++) {
    cout << *it << endl;
  }

  cout << endl;
  // Iterator range: [begin, end[
  cout << "First: " << *v2.begin() << endl;
  cout << "Last: " << *(v2.end() - 1) << endl;

  cout << endl;
  // Reverse iterators
  vector<int>::reverse_iterator rit;
  for (rit = v2.rbegin(); rit != v2.rend(); rit++) {
    cout << *rit << endl;
  }

  cout << "\nIs v2 empty? " << (v2.empty() ? "yes" : "no") << endl;
  cout << "Element at index 3: " << v2.at(3) << endl;

  v2.insert(v2.begin(), 100);
  v2.insert(v2.end() - 1, 100);

  cout << endl;
  cout << "New First: " << v2.front() << endl;
  cout << "New Last: " << v2.back() << endl;
  return 0;
}
