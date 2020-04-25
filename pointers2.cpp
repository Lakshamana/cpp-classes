#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[]) {
    char name[100];
    cout << "Digite um nome: ";
    cin >> name;

    int l = strlen(name);
    char *p = name + l - 1;

    while (p >= &name[0]) {
        cout << *p;
        p--;
    }
    cout << endl;
    return 0;
}
