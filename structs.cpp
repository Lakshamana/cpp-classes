#include <iostream>

using namespace std;

struct Person {
    private:
        char* name;
        int age;

    public:
        // Method/constructor impl can be out of this context
        Person(char *name, int age);

        Person(char *name);

        Person();

        char * get_name() {
            return this->name;
        }

        void set_name(char *name) {
            this->name = name;
        }

        int get_age() {
            return this->age;
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

    cout << person.get_name() << endl;
    cout << person.get_age() << endl;
    cout << "\nWith pointers:" << endl;

    Person *p = &person;
    cout << p->get_name() << endl;
    // cout << p->age << endl; cannot access private struct member
    cout << p->get_age() << endl;
    return 0;
}