#include <iostream>
#include <string.h>

using namespace std;

class FriendLanguage;

class Language {

    // Define friend pointer
    FriendLanguage *lfriend;

    // Define friend function
    friend void myFriend(Language &l);

    public:
        char name[100];

        Language(const char *name) {
            strcpy(this->name, name);
        }

        const char * getName() {
            return this->name;
        }

        void showFriend();
};

// We can also have friend classes
// Whenever we setup a class to be another's friend,
// it can acess its wrapper class members.
// e.g. Language can access all of FriendLanguage class members.
// Note the opposite is not true
class FriendLanguage {
    friend class Language;
    protected:
        void greet() {
            cout << "Hello from FriendLanguage!" << endl;
        }
};

// Implement friend function
void myFriend(Language &l) {
    cout << "Friend says: " << l.name << endl;
}

void Language::showFriend() {
    lfriend->greet();
}

int main(int argc, char *argv[]) {
    Language l("C++");
    // cout << "Language: " << l.name << endl;
    // myFriend(l);

    FriendLanguage fl;
    // cout << fl.getName() << endl; // error - FriendLanguage cannot acess Language methods
    l.showFriend();
    return 0;
}