#include <iostream>

using namespace std;

template <class T> class Stack {
  int maxLength;
  int top;
  T *items;

  public:
    Stack(int length) {
      items = new T[length];
      top = -1;
      maxLength = length;
    }

    ~Stack() {
      delete[] items;
      items = nullptr;
    }

    bool push(T item) {
      if (top == maxLength)
        return false;
      items[++top] = item;
      return true;
    }

    T pop() {
      if (top == -1)
        return nullptr;
      T item = items[top];
      items[top--] = nullptr;
      return item;
    }

    int get_top() {
      return top;
    }

    T * all() {
      return items;
    }

    void print() {
      if (top == -1) {
        cout << "Empty stack!" << endl;
        return;
      }
      for(int i = 0; i <= top; i++) {
        cout << items[i] << endl;
      }
    }
};

int main(int argc, char *argv[]) {
  int n = 5;
  Stack<int> stack1(n);
  int items1[] = {123, 12, 31, 56, 5};
  for (int i = 0; i < n; i++) {
    stack1.push(items1[i]);
  }
  stack1.print();

  cout << endl;
  char *items2 = (char *)"Hello World!";
  Stack<char> stack2(n);
  for (int i = 0; i < n; i++) {
    stack2.push(items2[i]);
  }
  stack2.print();

  cout << endl;
  const char* items3[] = {"Hello,", "babe", "are", "you", "fine?"};
  Stack<const char *> stack(n);
  for (int i = 0; i < n; i++) {
    stack.push(items3[i]);
  }
  stack.print();
  return 0;
}
