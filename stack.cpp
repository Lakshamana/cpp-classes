#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Item {
  int key;
  void *value;

  public:
    Item() {
      key = -1;
      value = nullptr;
    }

    Item(int key) {
      this->key = key;
      value = nullptr;
    }

    Item(int key, void* value) {
      this->key = key;
      this->value = value;
    }

    void set_value(void *value) {
      this->value = value;
    }

    int get_key() {
      return key;
    }

    void * get_vref() {
      return value;
    }
};

class Stack {
  int maxLength;
  int top;
  Item *items;

  public:
    Stack(int length) {
      items = new Item[length];
      top = -1;
      maxLength = length;
    }

    ~Stack() {
      delete[] items;
      items = nullptr;
    }

    bool push(Item item) {
      if (top == maxLength)
        return false;
      items[++top] = item;
      return true;
    }

    Item pop() {
      if (top == -1)
        return 0;
      Item item = items[top];
      items[top--] = 0;
      return item;
    }

    int get_top() {
      return top;
    }

    Item * all() {
      return items;
    }

    void print(char *(*fn)(void *value)) {
      if (top == -1) {
        cout << "Empty stack!" << endl;
        return;
      }
      for(int i = 0; i <= top; i++) {
        char *s = fn(items[i].get_vref());
        cout << s << endl;
        delete[] s;
      }
    }
};

char * cvrt_string(void *val) {
  int l = strlen((char *)val);
  char *s = new char[l];
  strcpy(s, (char *) val);
  return s;
}

char * cvrt_char(void *val) {
  char *c = new char[1];
  *c = *(char *)val;
  return c;
}

char * cvrt_int(void *val) {
  int n = *(int *)val;
  char *s = new char[10];
  sprintf(s, "%d", n);
  return s;
}

int main(int argc, char *argv[]) {
  int n = 5;
  Stack stack(n);
  // char *items = (char *)"Hello World!";
  // int items[] = {123, 12, 31, 56, 5};
  const char* items[] = {"Hello,", "babe", "are", "you", "fine?"};
  for (int i = 0; i < n; i++) {
    stack.push(Item(i, (char *) *(items + i)));
  }

  // cout << cvrt_char(item.get_vref()) << endl;
  stack.print(cvrt_string);
  // stack.print(cvrt_char);
  // stack.print(cvrt_int);
  return 0;
}
