#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

template<class t>
class Node {
  private:
    t val;
    Node<t>* lchild;
    Node<t>* rchild;

  public:
    Node(t value) {
      val = value;
      this->lchild = nullptr;
      this->rchild = nullptr;
    }

    virtual ~Node() {
      delete lchild;
      delete rchild;
      lchild = nullptr;
      rchild = nullptr;
    }

    t value() {
      return val;
    }

    void set_value(t value) {
      val = value;
    }

    Node* left() {
      return lchild;
    }

    void set_left(Node* node) {
      lchild = node;
    }

    Node* right() {
      return rchild;
    }

    void set_right(Node* node) {
      rchild = node;
    }

    bool leaf() {
      return !(lchild || rchild);
    }
};

template<class t>
class BinTree {
  private:
    Node<t>* root;

    void _insert(Node<t>* node, t key) {
      if (key < node->value()) {
        if (!node->left()) {
          Node<t>* child = new Node<t>(key);
          node->set_left(child);
        } else {
          _insert(node->left(), key);
        }
      } else if(key > node->value()) {
        if (!node->right()) {
          Node<t>* child = new Node<t>(key);
          node->set_right(child);
        } else {
          _insert(node->right(), key);
        }
      }
    }

    typedef pair<Node<t>*, Node<t>*> Pair;
    Pair _search(Node<t>* node, Node<t>* parent, t key) {
      if (!node) return make_pair(nullptr, nullptr);
      t val = node->value();
      if (key == val) {
        return make_pair(node, parent);
      }
      else if (!node->leaf()) {
        if (key < val)
          return _search(node->left(), node, key);
        else
          return _search(node->right(), node, key);
      }
      return make_pair(nullptr, nullptr);
    }

    void _print(Node<t>* node, int idt = 4, int level = 0) {
      if (node) {
        const char* endline = node->leaf() ? "" : "\n";
        cout << setw(idt * level) << "<" << node->value() << endline;
        _print(node->left(), idt, level + 1);
        _print(node->right(), idt, level + 1);
        if (!node->leaf())
          cout << setw(idt * level) << "/>" << endl;
        else
          cout << ">" << endl;
      }
    }

    // Just to learn I can get pointer to class member =p
    typedef void (Node<t>::*fn)(Node<t>*);
    fn _position(Node<t>* node, Node<t>* parent) {
      return node->value() < parent->value() ? &Node<t>::set_left : &Node<t>::set_right;
    }

    Pair _min(Node<t>* node, Node<t>* parent) {
      if (!node->left()) return make_pair(node, parent);
      return _min(node->right(), node);
    }

    bool _remove(Node<t>* node, Node<t>* parent) {
      if (node->leaf()) {
        if (parent) {
          fn setfn = _position(node, parent);
          (parent->*setfn)(nullptr);
        }
        delete node;
        return true;
      } else if(node->left() && node->right()) {
        Pair pair = _min(node->right(), node);
        Node<t>* right_min, *parent;
        tie(right_min, parent) = pair; // C++'s js-like destructuring
        node->set_value(right_min->value());
        return _remove(right_min, parent);
      } else {
        Node<t>* child = node->left() ? node->left() : node->right();
        if (parent) {
          fn setfn = _position(node, parent);
          (parent->*setfn)(child);
        } else root = child; // root only
        node->set_left(nullptr);
        node->set_right(nullptr);
        delete node;
        return true;
      }
      return false;
    }

  public:
    BinTree() {
      root = nullptr;
    }

    BinTree(t value) {
      root = new Node<t>(value);
    }

    virtual ~BinTree() {
      delete root;
      root = nullptr;
    }

    bool empty() {
      return root == nullptr;
    }

    void insert(t key) {
      if (empty()) {
        Node<t>* node = new Node<t>(key);
        root = node;
      } else {
        _insert(root, key);
      }
    }

    Node<t>* search(t key) {
      Pair nodes = _search(root, nullptr, key);
      return nodes.first;
    }

    bool remove(t key) {
      Pair nodes = _search(root, nullptr, key);
      Node<t>* node, *parent;
      tie(node, parent) = nodes;
      if (!node) return false;
      return _remove(node, parent);
    }

    void print() {
      _print(root);
      cout << endl;
    }

    Node<t>* get_root() {
      return root;
    }
};

int main(int argc, char *argv[]) {
  // BinTree<int> tree;
  // tree.insert(5);
  // tree.insert(3);
  // cout << "Root: " << tree.get_root()->value() << endl;
  // tree.insert(6);
  // tree.insert(7);
  // tree.insert(2);
  // tree.print();
  // cout << "Exists 7 in tree? " << (tree.search(7) ? "y" : "n") << endl;
  // cout << "Exists 4 in tree? " << (tree.search(4) ? "y" : "n") << endl;
  // tree.remove(5);
  // tree.print();

  BinTree<string> t;
  t.insert("C++");
  t.insert("C");
  t.insert("JavaScript");
  t.insert("Python");
  t.insert("Java");
  t.insert("Rust");
  t.insert("TypeScript");
  t.print();
  t.remove("C");
  cout << "After removing \'C\': " << endl;
  t.print();
  t.remove("JavaScript");
  cout << "After removing \'JavaScript\': " << endl;
  t.print();
  t.remove("C++");
  cout << "After removing \'C++\': " << endl;
  t.print();
  return 0;
}
