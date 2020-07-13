#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

class Graph {
  int n;
  list<int> *adj;
  bool cycle_dfs(int v);

  public:
    Graph(int n);
    void add_edge(int v1, int v2);
    int in_degree(int v);
    int out_degree(int v);
    bool is_neighbour(int v1, int v2);
    void dfs(int v);
    void bfs(int v);
    void has_cycle(int v);
    
};

Graph::Graph(int n) {
  this->n = n;
  this->adj = new list<int>[n];
}

void Graph::add_edge(int v1, int v2) {
  adj[v1].push_back(v2);
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
    visited[i] = false;
    stacked[i] = false;
  }

  stack.push(s);
  while (!stack.empty()) {
    int t = stack.top();
    stack.pop();
    if (!visited[t]) {
      cout << "Visiting: " << t << '\n';
      visited[t] = true;
      stacked[t] = true;
      list<int>::iterator it;
      for (it = adj[t].begin(); it != adj[t].end(); ++it) {
        if (stacked[*it]) return true;
        stack.push(*it);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  Graph g(4);
  g.add_edge(0, 1);
  g.add_edge(0, 3);
  g.add_edge(1, 2);
  g.add_edge(3, 1);
  g.add_edge(3, 2);

  cout << "Out degree for vtx 1: " << g.out_degree(1);
  cout << "\nOut degree for vtx 1: " << g.out_degree(3);
  cout << "\nIs neighbour (0, 1): " << (g.is_neighbour(0, 1) ? "true" : "false");
  cout << "\nIs neighbour (2, 0): " << (g.is_neighbour(2, 0) ? "true" : "false") << '\n';

  g.dfs(0);
  cout << '\n';
  g.bfs(0);
  return 0;
}