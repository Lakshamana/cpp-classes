#include <iostream>

using namespace std;

typedef struct atype {
  int data;
} AType;

int main(int argc, char *argv[]) {
  int a = 1;
  AType t = {1};
  AType *pa = &t, *pb = nullptr;
  cout << "xor: " << (pa->data ^ pb->data) << endl;
  return 0;
}
