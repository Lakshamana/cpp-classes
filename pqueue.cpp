#include <iostream>
#include <queue>

using namespace std;

class Person {
  int _age;
  string _name;

  public:
    Person(string name, int age) {
      _age = age;
      _name = name;
    }

    int age() {
      return _age;
    }

    string name() {
      return _name;
    }
};

// a functor
struct _cmpage {
  bool operator()(Person& p1, Person& p2) {
    return p1.age() < p2.age();
  }
};

int main(int argc, char *argv[]) {
  // min priority queue
  // priority_queue<int, vector<int>, greater<int>> pq;
  // max pqueue
  // priority_queue<int> pq;

  // pq.push(70);
  // pq.push(100);
  // pq.push(60);

  // cout << pq.top() << endl; // 100
  // cout << pq.empty() << endl; // 0
  // pq.pop();
  // cout << "Size after pop: " << pq.size() << endl; // 2
  priority_queue<Person, vector<Person>, _cmpage> pq;
  Person p1("John Doe", 20), p2("Mary Jane", 42), p3("Anastasya Krasnyy", 30);
  pq.push(p1);
  pq.push(p2);
  pq.push(p3);
  Person p = pq.top();
  cout << "Priority: " << p.name() << endl;
  return 0;
}
