#include <iostream>

using namespace std;

typedef struct Person {
    char* name;
    int age;

    Person(char *name, int age) {
        this->name = name;
        this->age = age;
    }

    Person(char *name) {
        this->name = name;
        this->age = 0;
    }

    Person() {
        this->name = "";
        this->age = 0;
    }

    void set_name(char *name) {
        this->name = name;
    }

    void set_age(int age) {
        this->age = age;
    }
};


int main(int argc, char *argv[]) {
    Person person("Lakshamana", 22);

    cout << person.name << endl;
    cout << person.age << endl;
    cout << "With pointers:" << endl;

    Person *p = &person;
    cout << p->name << endl;
    cout << p->age << endl;
    return 0;
}