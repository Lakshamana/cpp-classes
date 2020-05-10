#include <iostream>

using namespace std;

template<class t>
class Node {
  t value;
  Node* next;

  public:
    Node(t value) {
      this->value = value;
      this->next = nullptr;
    }

    virtual ~Node() {
      delete next;
    }

    t get_value() {
      return value;
    }

    void set_value(t value) {
      this->value = value;
    }

    Node* get_next() {
      return next;
    }

    void set_next(Node* node) {
      next = node;
    }
};

template<typename t>
class List {
  Node<t>* root;
  Node<t>* tail;

  public:
    List() {
      root = nullptr;
      tail = nullptr;
    }

    List(t value) {
      root = new Node<t>(value);
      tail = root;
    }

    virtual ~List() {
      delete root;
    }

    bool empty() {
      return !root;
    }

    void insert_head(t value) {
      Node<t>* node = new Node<t>(value);
      node->set_next(root);
      root = node;
    }

    void insert_tail(t value) {
      Node<t>* node = new Node<t>(value);
      if (empty()) {
        root = node;
        tail = root;
        return;
      }
      tail->set_next(node);
      tail = node;
    }

    void insert_at(int pos, t value) {
      int p = 0;
      Node<t>* previous = root;
      Node<t>* next = root;
      while (p < pos) {
        previous = next;
        next = next->get_next();
        p++;
      }
      Node<t>* node = new Node<t>(value);
      previous->set_next(node);
      node->set_next(next);
    }

    t first() {
      return root->get_value();
    }

    t last() {
      return tail->get_value();
    }

    t get(int index) {
      int i = 0;
      Node<t>* node = root;
      while (i < index) {
        node = node->get_next();
        i++;
      }
      return node->get_value();
    }

    void remove_head() {
      if (empty()) return;
      Node<t>* node = root;
      root = node->get_next();
      node->set_next(nullptr);
      delete node;
      node = nullptr;
    }

    void remove_tail() {
      if (empty()) return;
      Node<t>* prev = root;
      while (prev->get_next() != tail) {
        prev = prev->get_next();
      }
      Node<t>* node = tail;
      tail = prev;
      tail->set_next(nullptr);
      delete node;
      node = nullptr;
    }

    void remove_at(int index) {
      if (empty()) return;
      int i = 0;
      Node<t>* previous = root;
      Node<t>* rmvNode = root;
      while (i < index) {
        previous = rmvNode;
        rmvNode = rmvNode->get_next();
        i++;
      }
      previous->set_next(rmvNode->get_next());
      rmvNode->set_next(nullptr);
      delete rmvNode;
      rmvNode = nullptr;
    }

    int length() {
      int i = 0;
      if (empty()) return 0;
      Node<t>* node = root;
      while (node) {
        node = node->get_next();
        i++;
      }
      return i;
    }

    bool exists(t value) {
      Node<t>* node = root;
      while (node) {
        if (node->get_value() == value)
          return true;
        node = node->get_next();
      }
      return false;
    }

    void replace(int index, t value) {
      int i = 0;
      Node<t>* node = root;
      while (i < index) {
        node = node->get_next();
        i++;
      }
      node->set_value(value);
    }

    int index(t value) {
      int i = 0;
      Node<t>* node = root;
      while (node) {
        if (node->get_value() == value)
          return i;
        node = node->get_next();
        i++;
      }
      return -1;
    }

    int last_index(t value) {
      int i = 0;
      int last = -1;
      Node<t>* node = root;
      while (node) {
        if (node->get_value() == value)
          last = i;
        node = node->get_next();
        i++;
      }
      return last;
    }

    void print() {
      Node<t>* node = root;
      while (node) {
        cout << node->get_value() << " ";
        node = node->get_next();
      }
      cout << endl;
    }
};

int main(int argc, char *argv[]) {
  List<int> l;
  l.insert_tail(3);
  l.insert_tail(3);
  l.insert_tail(4);
  l.insert_head(0);
  l.insert_at(1, 1);
  l.print();

  int i = 2;
  printf("Value at %i: ", i);
  cout << l.get(i) << endl;

  cout << "\nList after remove 2nd index el & filling it with '2':" << endl;
  l.remove_at(2); // remove
  l.insert_at(2, 2); // insert
  l.print();

  l.remove_head();
  l.remove_tail();
  l.print();

  cout << "\nExists item = 3? " << (l.exists(3) ? "y" : "n") << endl;
  cout << "First: " << l.first() << endl;
  cout << "Last: " << l.last() << endl;

  l.insert_tail(1);
  l.insert_tail(3);
  cout << endl;
  l.print();
  cout << "First index of 3: " << l.index(3) << endl;
  cout << "Last index of 3: " << l.last_index(3) << endl;
  cout << "First index of 10: " << l.index(10) << endl;
  cout << "Last index of 7: " << l.last_index(7) << endl;
  cout << "\nList final length: " << l.length() << endl;
  return 0;
}
