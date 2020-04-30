#include <iostream>
#include <string.h>

using namespace std;

class Animal {
  protected:
    char *noise;
    int legs;

  public:
    // We can have default parameters
    Animal(const char *noise, int legs = 0) {
      int l = strlen(noise) + 1;
      this->noise = new char[l];
      strcpy(this->noise, noise);
      this->legs = legs;
    }

    ~Animal() {
      delete[] noise;
      noise = nullptr;
    }

    char * getNoise() {
      return noise;
    }

    void setLegs(int legs) {
      this->legs = legs;
    }

    int getLegs() {
      return legs;
    }
};

class Dog : public Animal {
  protected:
    int age;

  public:
    Dog(int age) : Animal("woof!", 4) {
      this->age = age;
    }

    void setAge() {
      this->age = age;
    }

    int getAge() {
      return age;
    }
};

int main(int argc, char *argv[]) {
  Dog d(5);

  cout << "Noise: " << d.getNoise() << endl;
  cout << "Legs: " << d.getLegs() << endl;
  cout << "Age: " << d.getAge() << endl;
  return 0;
}
