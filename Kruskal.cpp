#include <iostream>
#include <fstream>
#include <map>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
  int v1, v2, weight;
  
  public:
    Edge(int v1, int v2, int weight) {
      this->v1 = v1;
      this->v2 = v2;
      this->weight = weight;
    }

    int get_v1() const { return v1; }
    int get_v2() const { return v2; }
    int get_weight() const { return weight; }

    friend istream& operator>>(istream& is, Edge& e) {
      is >> e.v1 >> e.v2 >> e.weight;
      return is;
    }

    bool operator<(const Edge& e) {
      return weight < e.weight;
    }
};

class Graph {
  int n;
  vector<Edge> edges;
  
  public:
  Graph(int n) {
    this->n = n;
  }

  void add_edge(Edge e) { 
    edges.push_back(e); 
  }

  void add_edge(int v1, int v2, int weight) {
    edges.push_back(Edge(v1, v2, weight));
  }

  int find(vector<int>& subset, int i) {
    return subset[i] == -1 ? i : find(subset, subset[i]);
  }

  void join(vector<int>& subset, int v1, int v2) {
    int v1_set = find(subset, v1);
    int v2_set = find(subset, v2);
    subset[v1_set] = v2_set;
  }

  void kruskal () {
    vector<Edge> tree;
    int length = edges.size();

    sort(edges.begin(), edges.end());
    vector<int> subset(n, -1);

    for (int i = 0; i < length; ++i) {
      int v1 = find(subset, edges[i].get_v1());
      int v2 = find(subset, edges[i].get_v2());

      if (v1 != v2) {
        tree.push_back(edges[i]);
        join(subset, v1, v2);
      }
    }

    int l = tree.size();
    for (int i = 0; i < l; ++i) {
      char v1 = 'A' + edges[i].get_v1();
      char v2 = 'A' + edges[i].get_v2();
      printf("(%c, %c) =  %i\n", v1, v2, edges[i].get_weight());
    }
  }
};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Usage: Kruskal FILE where FILE is a file whose content is to be\n\n" 
      << "LINE [LINE]...\n"
      << "where LINE := { "
      << "vertex1 vertex2 weight\\n"
      << " }\n\n";
    return 1;
  }

  vector<Edge> edges;
  ifstream is(argv[1]);
  int i = 0;

  Edge e(0, 0, 0);
  if (is.good()) {
    while (!is.eof()) {
      is >> e;
      edges.push_back(e);
      ++i;
    }
    is.close();
  } else {
    cout << "Error on open file" << endl;
  }

  Graph g(i);
  int l = edges.size();
  for (int i = 0; i < l; ++i) {
    g.add_edge(edges[i]);
  }
  g.kruskal();

  return 0;
}