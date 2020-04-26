#include <iostream>

using namespace std;

typedef struct person {
    char* name;
    int age;
} t_person;


int main(int argc, char *argv[]) {
    t_person persons[10];
    t_person *p = persons;
    char *c = "Lakshamana";

    p->name = c;
    p->age = 22;

    cout << p->name << endl;
    cout << p->age << endl;
    return 0;
}