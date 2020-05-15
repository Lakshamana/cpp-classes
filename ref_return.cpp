#include <iostream>

using namespace std;

typedef struct _person {
  string name;
  int age;
  double height, weight;
} Person;


double& bmi(Person& p) {
  const double h = p.height;
  double result = p.weight / (h * h);
  double& d = result;
  return d;
}

int main(int argc, char *argv[]) {
  Person p = {"John Doe", 20, 1.77, 67 };
  cout << "BMI: " << bmi(p) << endl;
  return 0;
}
