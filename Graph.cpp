#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <string.h>

using namespace std;

class Graph {
  int n;
  list<int> *adj;
  bool cycle_dfs(int v);
  int _find(vector<int>& subset, int v);
  void _union(vector<int>& subset, int v1, int v2);

  public:
    Graph(int n);
    void add_edge(int v1, int v2);
    int in_degree(int v);
    int out_degree(int v);
    bool is_neighbour(int v1, int v2);
    void dfs(int v);
    void bfs(int v);
    bool has_cycle();
    bool union_find();
};

Graph::Graph(int n) {
  this->n = n;
  this->adj = new list<int>[n];
}

void Graph::add_edge(int v1, int v2) {
  adj[v1].push_back(v2);
  adj[v2].push_back(v1);
}

int Graph::out_degree(int v) {
  return adj[v].size();
}

int Graph::in_degree(int v) {
  int s = 0;
  for (int i = 0; i < this->n; ++i) {
    if (i == v) continue;
    for (int j : adj[i]) {
      if (v == j) ++s;
    }
  }
  return s;
}

bool Graph::is_neighbour(int v, int u) {
  return find(adj[v].begin(), adj[v].end(), u) != adj[v].end();
}

void Graph::dfs(int v) {
  stack<int> stack;
  bool visited[this->n];
  for (int i = 0; i < this->n; ++i) {
    visited[i] = false;
  }

  stack.push(v);
  while (!stack.empty()) {
    int t = stack.top();
    stack.pop();
    if (!visited[t]) {
      cout << "Visiting: " << t << '\n';
      visited[t] = true;
      list<int>::iterator it;
      for (it = adj[t].begin(); it != adj[t].end(); ++it) {
        stack.push(*it);
      }
    }
  }
}

void Graph::bfs(int v) {
  queue<int> q;
  bool visited[this->n];
  for (int i = 0; i < this->n; ++i) {
    visited[i] = false;
  }

  q.push(v);
  while (!q.empty()) {
    int f = q.front();
    cout << "Visiting: " << f << '\n';
    q.pop();
    list<int>::iterator it;
    for (it = adj[f].begin(); it != adj[f].end(); ++it) {
      if (!visited[*it]) {
        visited[*it] = true;
        q.push(*it);
      }
    }
  }
}

bool Graph::cycle_dfs(int s) {
  stack<int> stack;
  bool visited[this->n], stacked[this->n];
  for (int i = 0; i < this->n; ++i) {
    visited[i] = stacked[i] = false;
  }

  stack.push(s);
  while (!stack.empty()) {
    int t = stack.top();
    stack.pop();
    stacked[t] = false;
    if (!visited[t]) {
      visited[t] = true;
      list<int>::iterator it;
      for (it = adj[t].begin(); it != adj[t].end(); ++it) {
        if (visited[*it] && *it == s) return true;
        else if (visited[*it]) {
          continue;  
        }
        if (!stacked[*it]) {
          stack.push(*it);
          stacked[*it] = true;
        }
      }
    }
  }
  return false;
}

bool Graph::has_cycle() {
  for (int i = 0; i < n; ++i) {
    if (this->cycle_dfs(i)) {
      return true;
    }
  }
  return false;
}

int Graph::_find(vector<int>& subset, int v) {
  return subset[v] == -1 ? v : _find(subset, subset[v]);
}

void Graph::_union(vector<int>& subset, int v1, int v2) {
  int v1_set = _find(subset, v1);
  int v2_set = _find(subset, v2);
  subset[v1_set] = v2_set;
}

bool Graph::union_find() {
  vector<int> subset(this->n, -1);
  // memset(subset, -1, this->n * sizeof(int));
  // vector<int>* flags = (vector<int>*) malloc(this->n * sizeof(vector<int>));
  // for (int i = 0; i < this->n; ++i) {
  //   flags[i] = (vector<int>) calloc(this->n, sizeof(int));
  // }
  
  map<string, bool> m;
  for (int i = 0; i < this->n; ++i) {
    list<int>::iterator it;
    for (it = adj[i].begin(); it != adj[i].end(); ++it) {
      printf("%d, %d = %d\n", *it, i, m[to_string(*it) + to_string(i)]);
      if (!m[to_string(*it) + to_string(i)]) {
        m[to_string(i) + to_string(*it)] = true;
        int v1 = this->_find(subset, i);
        int v2 = this->_find(subset, *it);
        if (v1 != v2) {
          this->_union(subset, v1, v2);
        } else return true;
      }
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  Graph g(4);
  g.add_edge(0, 1);
  g.add_edge(0, 3);
  g.add_edge(1, 2);
  // g.add_edge(3, 1);
  // g.add_edge(3, 2);
  // g.add_edge(2, 0);

  cout << "Has cycle? " << (g.union_find() ? "yes" : "no") << '\n';
  return 0;
}