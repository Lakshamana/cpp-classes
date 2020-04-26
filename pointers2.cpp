#include <iostream>
#include <string.h>

using namespace std;

int _strlen(char *s) {
    int i = 0;
    while (*(s + i) != '\0') i++;
    return i;
}

char * cat(char *s1, char *s2) {
    const int l1 = _strlen(s1), l2 = _strlen(s2);
    char *r = s1;
    for (int i = 0; i < l1; i++) {
        *(r + i) = *(s1 + i);
    }
    for (int i = 0; i < l2; i++) {
        *(r + l1 + i) = *(s2 + i);
    }
    *(r + l1 + l2) = '\0';
    return r;
}

int main(int argc, char const *argv[]) {
    char *name1 = new char[100];
    char *name2 = new char[100];

    cout << "Type in a word: ";
    cin >> name1;
    cout << "Type in other word: ";
    cin >> name2;

    cout << "Concat: " << cat(name1, name2) << endl;
    return 0;
}
