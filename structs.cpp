#include <iostream>

using namespace std;

typedef struct person {
    char* name;
    int age;

    void set_name(char *name) {
        this->name = name;
    }

    void set_age(int age) {
        this->age = age;
    }
} t_person;


int main(int argc, char *argv[]) {
    t_person persons[10];
    t_person *p = persons;
    char *c = "Lakshamana";

    p->set_name(c);
    p->set_age(22);

    cout << p->name << endl;
    cout << p->age << endl;
    return 0;
}