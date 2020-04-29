#include <iostream>
#include <string.h>

using namespace std;

class Person {
    private:
        char name[100];
        int age;
        int *relatives;

    public:
        Person(const char *name, int age) {
            this->age = age;
            strcpy(this->name, name);
            this->relatives = new int[100];
            cout << "Got into contructor: " << name << endl;
        }

        ~Person() {
            cout << "Got into destructor: " << this->name << endl;
            delete[] relatives;
        }

        char * getName() {
            return this->name;
        }

        int getAge() {
            return this->age;
        }
};

int main(int argc, char *argv[]) {
    Person p[3] = {
        {"John Doe", 26},
        {"Mary Jane", 32},
        {"Jeannine Bigalow", 34}
    };
    
    cout << "--Before end--" << endl;
    // Destructors are called after program ends
    return 0;
}