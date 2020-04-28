#include <iostream>
#include <string.h>

using namespace std;

class Person {
    public:
        char name[100];
        char cpf[12];
        int age;
};

int get_age(int length, Person *persons, char *name) {
    for (int i = 0; i < length; i++) {
        if (strcmp(persons[i].name, name) == 0) {
            return persons[i].age;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    // We can initialize classes like this
    // Person p = {"John Doe", "11111111111", 30};
    Person persons[3] = {
        {"John Doe", "11111111111", 30},
        {"Marco Polo", "11111111112", 25},
        {"Penelope Lopez", "11111111113", 19}
    };

    cout << "Name: " << persons[0].name << endl;
    char *name = (char *) "Marco Polo";
    int length = sizeof(persons) / sizeof(Person);

    int age = get_age(3, persons, name);
    const char * result = age > 0 ? to_string(age).c_str() : (char *) "Person not found";
    printf("Age of %s = %s\n", name, result);
    return 0;
}