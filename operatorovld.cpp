#include <iostream>

using namespace std;

// Consider Complex number set as
// user-defined data structure, which
// will be used to illustrate operator overloading
class Complex {
  public:
    int real, img;
    Complex(int real, int img) {
      this->real = real;
      this->img = img;
    }

    // Operator '+' overload, whose arg Complex& x
    // is the second parcel on the sum
    Complex operator+(Complex& x) {
      return Complex(real + x.real, img + x.img);
    }
};

int main(int argc, char *argv[]) {
  // Consider + as a int operator
  // int a = 2, b = 2;
  // cout << a + b << endl;

  // Operator overloading should apply to user-defined
  // data structures operations addressing one or more
  // than one of these structures objects

  Complex c1(1, 2), c2(3, 4);
  Complex c3 = c1 + c2;

  cout << "Real part: " << c3.real << endl;
  cout << "Imaginary part: " << c3.img << endl;
  return 0;
}
