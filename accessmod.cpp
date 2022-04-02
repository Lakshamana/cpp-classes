#include <iostream>
#include <string.h>

using namespace std;

class FriendLanguage;

class Language {

    // Define friend pointer
    FriendLanguage *lfriend;

    // Define friend function
    friend void myFriend(Language &l) {
        cout << "Friend says: " << l.name << endl;
    }

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
// Whenever we setup a class to be another's friend e.g. (Language friend of FriendLanguage),
// it can acess its wrapper (FriendLanguage) class members.
// e.g. Language can access all of FriendLanguage class members.
// Note the opposite is not true
class FriendLanguage {
    friend class Language;
    protected:
        void greet() {
            cout << "Hello from FriendLanguage!" << endl;
        }
};

void Language::showFriend() {
    lfriend->greet();
}

int main(int argc, char *argv[]) {
    Language l("C++");
    cout << "Language: " << l.name << endl;
    // you may access myFriend outside Language's scope, as this is a friend function
    // in fact, friend functions belong to global scope
    // hint: try to define a function called `myFriend` inside FriendLanguage
    myFriend(l);

    FriendLanguage fl;
    // you can't access fl's greet directly, as this is a protected function
    // cout << fl.getName() << endl; // error - FriendLanguage cannot acess Language methods
    l.showFriend();
    return 0;
}
