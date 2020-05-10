#include <iostream>

using namespace std;

class A {
  public:
    class B {
      int var;
        public:
          B(int var) {
            this->var = var;
          }

          int get_var() {
            return var;
          }
    };
};

int main(int argc, char *argv[]) {
  A::B obj(10);
  cout << "Value: " << obj.get_var() << endl;
  return 0;
}
