#include <iostream>
#include <string.h>

using namespace std;

class Student {
    private:
        int age;
        char *name;
    
    public:
        Student(const char* name) {
            age = 0;
            int l = strlen(name) + 1;
            this->name = new char[l];
            strcpy(this->name, name);
        }

        // Copy contructor
        Student(const Student& s) {
            age = s.age;
            // add " (copied)"
            int l = strlen(s.name) + 10;
            name = new char[l];
            strcpy(name, s.name);
            strcat(name, " (copied)");
        }

        ~Student() {
            cout << "Destroy student: " << name << endl;
            cout << "Free memaddr: " << this << endl << endl;
            delete[] name;
            name = NULL;
        }

        char * getName() {
            return name;
        }

        int getAge() {
            return age;
        }
};

// This function receives copy returned
// from our Student(const Student&)
void foo(Student s) {
    cout << "Name: " << s.getName() << endl;
    cout << "MemAddr: " << &s << endl << endl;
}

int main(int argc, char *argv[]) {
    Student s("John Doe");
    cout << "Name: " << s.getName() << endl;
    cout << "MemAddr: " << &s << endl << endl;
    foo(s);
    return 0;
}