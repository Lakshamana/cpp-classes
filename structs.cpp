#include <iostream>

using namespace std;

typedef struct Person {
    char* name;
    int age;

    // Method/constructor impl can be out of this context
    Person(char *name, int age);

    Person(char *name);

    Person();

    void set_name(char *name) {
        this->name = name;
    }

    void set_age(int age) {
        this->age = age;
    }
};

// Use scope resolution operator (::)
// to indicate of what context Person's 
// constructor belongs to
Person::Person(char *name, int age) {
    this->name = name;
    this->age = age;
}

Person::Person(char *name) {
    this->name = name;
    this->age = 0;
}

Person::Person() {
    this->name = "";
    this->age = 0;
}

int main(int argc, char *argv[]) {
    Person person("Lakshamana", 22);

    cout << person.name << endl;
    cout << person.age << endl;
    cout << "\nWith pointers:" << endl;

    Person *p = &person;
    cout << p->name << endl;
    cout << p->age << endl;
    return 0;
}