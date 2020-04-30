#include <iostream>

using namespace std;

class Base {
  public:
    void showMessage() {
      cout << "Hello from Base!" << endl;
    }

    virtual void virtualShowMessage() {
      cout << "Virtual hello from Base!" << endl;
    }
};

class Child : public Base {
  public:
    void showMessage() {
      cout << "Hello from Child!" << endl;
    }

    // virtual not necessary in subclasses
    void virtualShowMessage() {
      cout << "Virtual hello from Child!" << endl;
    }
};

void foo(Base& b) {
  b.showMessage();
}

void bar(Base& b) {
  b.virtualShowMessage();
}

int main(int argc, char *argv[]) {
  Base base;
  Child child;

  base.showMessage(); //Hello from Base!
  child.showMessage(); //Hello from Child!

  cout << endl;
  foo(base);
  foo(child); // Hello from Base!, cause foo takes Base& arg (without virtual)

  cout << endl;
  bar(base);
  bar(child); // Hello from Child! (with virtual)
  return 0;
}
