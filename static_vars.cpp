#include <iostream>

using namespace std;

int generateID() {
  static int id = 0;
  return id++;
}

int main(int argc, char *argv[]) {
  string name;
  while (true) {
    cout << "Type in a name: ";
    cin >> name;
    printf("Generated id for %s: %i\n", name.c_str(), generateID());
    cout << "-> Continue? y/n: ";
    string option;
    cin >> option;
    if (option != "y") break;
  }
  return 0;
}
