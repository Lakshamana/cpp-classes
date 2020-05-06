#include <iostream>
#include <exception>

using namespace std;

class CustomException : public exception {
  protected:
    string msg;
  public:
    CustomException(const char* s) {
      msg = string(s);
    }

    // Override what super method
    virtual const char* what() {
      return msg.c_str();
    }
};

int fat(int n) {
  if (n < 0)
    throw "Argument should be >= 0!";
  return n == 0 ? 1 : n * fat(n - 1);
}

int fat2(int n) {
  if (n < 0)
    throw CustomException("Argument should be >= 0!");
  return n == 0 ? 1 : n * fat(n - 1);
}

int main(int argc, char *argv[]) {
  try {
    printf("%i! = %i\n", 5, fat2(5));
    printf("%i! = %i\n", -5, fat2(-5));
  } catch(CustomException e) {
    cerr << "Error: " << e.what() << endl;
  // } catch(const char *s) {
  //   cerr << "Error: " << s << endl;
  } catch(...) {
    cerr << "Unexpected error" << endl;
  }
  return 0;
}
