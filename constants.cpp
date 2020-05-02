#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    // const double PI; - error, should be initialized on definition
    const double PI = 3.14156; // OK

    // p1 & p2 are pointers to const int array,
    // that is, items inside array cannot be changed,
    // however p[1, 2] can change the mem address
    const int *p1; // pointer to constant int array
    int const *p2; // pointer to constant int array

    const int v[] = {1, 2, 3};

    // p3 however is a int* to a constant mem address
    int *const p3 = new int[3]; // constant pointer to int array

    p1 = v;
    p2 = v + 2;

    cout << *p1 << endl; // 1
    cout << *p2 << endl; // 3

    // *p1 = 10; // error - should not modify derreference value
    p2 = v + 1; // we can change mem address for p2, however
    cout << *p2 << endl; // 2

    for (int i = 0; i < 3; i++) {
        *(p3 + i) = i + 1; // its derreference values can be changed
        printf("p3[%d] = %d\n", i, *(p3 + i));
    }

    p3[0] = 100;
    cout << "Changed p3[0] to " << *p3 << endl;

    // We can even have a constant pointer to constant values array
    const char* const p4 = "Lakshamana";
    // p4 = new char[100]; error - cannot change p4's mem address
    // p4[1] = "v"; error - cannot change *(p4 + 1) to another value

    // Notice that int v[] = int const *v
    int v2[3];
    int *pt = NULL;
    // v2 = pt; // error - cannot change v2's memaddr, values allowed only
    v2[0] = 0;
    cout << *v2 << endl; // 0

    return 0;
}
