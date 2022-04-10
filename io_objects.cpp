#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <functional>

using namespace std;

class Person {
  string name;
  int age;

  public:
    Person(string name = "", int age = 0) {
      this->name = name;
      this->age = age;
    }

    int get_age() {
      return age;
    }

    string& get_name() {
      return name;
    }

    void set_name(string& name) {
      this->name = name;
    }

    void set_age(int age) {
      this->age = age;
    }

    friend ostream& operator<<(ostream& os, const Person& p) {
      os << '\n' << p.name << endl;
      os << p.age << endl;
      return os;
    }

    friend istream& operator>>(istream& is, Person& p) {
      is >> p.name >> p.age;
      return is;
    }
};

char menu() {
  char r;
  cout << "Type an option from below:\n";
  cout << "1. Show person list\n";
  cout << "2. Add person\n";
  cout << "3. Remove person\n";
  cout << "0. out\n";
  cout << "[option]: ";
  cin >> r;
  return r;
}

void scan(ifstream& is, function<void(Person& p)> fn) {
  Person p;
  if (is.good()) {
    while (!is.eof()) {
      is >> p;
      fn(p);
    }
    is.close();
  } else {
    cout << "Error on open file" << endl;
  }
}

int main(int argc, char *argv[]) {
  // mark second entry as void function
  typedef void (*funct)();
  map<const char, funct> actions = {
    make_pair('1', []() {
      cout << "\nListing people...\n" << endl;
      ifstream is("output/file.txt");
      scan(is, [](Person& p) {
        cout << "Name: " << p.get_name() << endl;
        cout << "Age: " << p.get_age() << endl << endl;
      });
    }),
    make_pair('2', []() {
      cout << "\nAdd a person...\n" << endl;
      string name;
      int age;
      cout << "Type in person's name: ";
      cin >> name;
      cout << "Type in person's age: ";
      cin >> age;
      cout << endl;
      Person p(name, age);
      ofstream os("file.txt", ofstream::app); // app -> append
      os << p;
      os.close();
    }),
    make_pair('3', []() { 
      cout << "\nRemove a person...\n" ;
      string name;
      cout << "Type in person's name to remove: ";
      cin >> name;
      ifstream is("file.txt");
      ofstream os("file.tmp.txt");
      string last = "";
      scan(is, [&](Person& p) {
        if (p.get_name() == name) {
          cout << "Removing entry with name: " << name << endl;
        } else {
          os << p;
        }
      });
      os.close();
      remove("file.txt");
      rename("file.tmp.txt", "file.txt");
    }),
    make_pair('0', []() { cout << "\nGetting out...\n" << endl; })
  };

  while (true) {
    char r = menu();
    const funct fn = actions[r];
    if (!fn) {
      cout << "\nSelect a valid option...\n" << endl; 
      continue;
    }
    fn();
    if (r == '0') break;
  }
  return 0;
}
