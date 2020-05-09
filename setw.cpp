#include <iostream>
#include <iomanip>

using namespace std;

class Person {
  public:
    string name;
    int age;

    Person(const string& name, const int& age) {
      this->name.assign(name);
      this->age = age;
    }
};

int main(int argc, char *argv[]) {
  Person persons[] = {
    {"John Doe", 20},
    {"Mary Jane", 26},
    {"Anastasya Sotnikova", 31}
  };
  int l = sizeof(persons) / sizeof(Person);
  cout << setw(20) << "Person's name" << setw(10) << "Age" << endl;
  for (int i = 0; i < l; i++) {
    cout << setw(20) << persons[i].name << setw(10) << persons[i].age << endl;
  }
  return 0;
}
