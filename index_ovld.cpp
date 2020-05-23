#include <iostream>
#define MAX 1000

using namespace std;

template <class t>
class Array {
  t* array;
  int max;

  public:
    Array(int max = MAX) {
      this->max = max;
      array = (t*) calloc(max, sizeof(t));
    }

    ~Array() {
      free(array);
      array = nullptr;
    }

    bool insert(t val, int pos) {
      if (pos < max && pos > -1) {
        array[pos] = val;
        return true;
      }
      return false;
    }

    int& operator[](int i) {
      if (i < 0 || i >= max) {
        throw "Error: invalid index access.";
      }
      return array[i];
    }

    int get_max() {
      return max;
    }
};

template <class t = int>
void print(Array<t>& array) {
  int l = array.get_max();
  for (int i = 0; i < l; i++) {
    cout << array[i] << " ";
    // cout << *(array + i) << " "; error: no operation+ Array<t> and t found
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  Array<int> array(3);
  array.insert(1, 0);
  array.insert(2, 1);
  array.insert(3, 2);

  try {
    print(array);
  } catch(const char* msg) {
    cout << endl << msg << endl;
  }
  return 0;
}
