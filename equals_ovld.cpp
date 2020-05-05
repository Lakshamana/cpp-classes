#include <iostream>
#include <string.h>

using namespace std;

class Person {
  private:
    char *name;
    int id;

  public:
    void init(const char *name, int id) {
      int l = strlen(name);
      this->name = new char[l];
      strcpy(this->name, name);
      this->id = id;
    }

    Person(const char *name, int id) {
      init(name, id);
    }

    Person(Person& p) {
      init(p.name, p.id);
    }

    void destroy() {
      delete[] name;
      name = nullptr;
    }

    ~Person() {
      destroy();
    }

    Person& operator=(Person& p) {
      if (this != &p) {
        destroy();
        init(p.name, p.id);
      }
      return *this;
    }

    char * get_name() {
      return name;
    }

    int get_id() {
      return id;
    }

    void changeFirstLetter(char c) {
      *name = c;
    }
};

int main(int argc, char *argv[]) {
  Person p1("John Doe", 1), p2("Mary Jane", 2);
  p1 = p2; // Deep copy!
  p1.changeFirstLetter('T');

  printf("Name: %s, id: %d, memaddr: %x\n", p1.get_name(), p1.get_id(), &p1);
  printf("Name: %s, id: %d, memaddr: %x\n", p2.get_name(), p2.get_id(), &p2);
  return 0;
}
