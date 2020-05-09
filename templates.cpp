#include <iostream>
#include <list>

using namespace std;

template<class T>
class Queue {
  list<T> q;

  public:
    void insert(const T& e) {
      q.push_back(e);
    }

    T pop() {
      if (!q.empty()) {
        T el = q.front();
        q.pop_front();
        return el;
      } else throw "Empty Queue!";
    }

    T first() {
      if (!q.empty())
        return q.front();
      else throw "Empty Queue!";
    }

    T last() {
      if (!q.empty())
        return q.back();
      else throw "Empty Queue!";
    }

    void print(const char* endq = " ") {
      for (T& i : q) {
        cout << i << endq;
      }
      cout << endl;
    }

    int length() {
      return q.size();
    }
};

int main(int argc, char *argv[]) {
  Queue<double> q;
  q.insert(3.141);
  q.insert(2.718);
  q.insert(1.618);

  // test exception
  while (true) {
    try {
      q.print();
      q.pop();
    } catch (const char* msg) {
      cerr << "Error: " << msg << endl;
      break;
    }
  }

  cout << endl;
  Queue<const char*> qq;
  qq.insert("Pascal");
  qq.insert("C");
  qq.insert("Java");
  qq.insert("Prolog");
  qq.insert("Python");
  qq.insert("JavaScript");
  qq.insert("TypeScript");
  qq.insert("Learning: C++");
  qq.insert("Todo: Rust");
  qq.insert("Todo: Elixir");

  // test exception
  while (true) {
    try {
      qq.print();
      qq.pop();
    } catch (const char* msg) {
      cerr << "Error: " << msg << endl;
      break;
    }
  }
  return 0;
}
