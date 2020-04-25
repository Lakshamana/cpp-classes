#include <iostream>
#include <list>
#include <stdlib.h>
// #include <format>

using namespace std;

int main() {
  int n = 10;
  int *p = &n;
  cout << "Pointer value: " << *p << endl;
  cout << "Pointer address: " << p << endl;

  list<int> l;
  list<int>::iterator i = l.begin();
  l.push_front(*p);
  cout << endl << *i << endl;

  // int *vet = (int *) malloc(3 * sizeof(int *));
  int vet[3];
  *vet = 15;
  *(vet + 1) = 30;
  vet[2] = 60;

  int len = sizeof(vet) / sizeof(int); // works with vectors only
  cout << "len: " << len << endl;
  cout << sizeof(vet) << sizeof(int) << sizeof(int *) << endl;
  for (int i = 0; i < len; i++) {
    cout << "Pointer as list: " << *(vet + i) << endl;
  }


  cout << "Write a number: ";
  cin >> *p;

  cout << "number = " << *p << endl;
  delete[] p;
  p = NULL;
  cout << "number = " << *p << endl; // invalid pointer
  // cout << format("!{} = {}", *p, fat(*p));
  
  return 0;
}

int fat(int n) {
  return n == 0 ? 1 : n * fat(n - 1);
}