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

  public:
    List() {
      root = nullptr;
    }

    List(t value) {
      root = new Node<t>(value);
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
        return;
      }
      Node<t>* last = root;
      while (last->get_next()) {
        last = last->get_next();
      }
      last->set_next(node);
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

    t get(int index) {
      int i = 0;
      Node<t>* node = root;
      while (i < index) {
        node = node->get_next();
        i++;
      }
      return node->get_value();
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
  printf("\nValue at %i: ", i);
  cout << l.get(i) << endl;
  return 0;
}
