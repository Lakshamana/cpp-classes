#include <cstring>
#include <iomanip>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;

const int MAX_WEIGHT = 20;

void print_matrix(int r, int c, int* v, int indent = 2) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << setw(indent) << *((v + i * c) + j) << " ";
        }
        cout << endl;
    }
}

tuple<int, set<int>> knapsack(int b[], int wt[], int n) {
    int v[n + 1][MAX_WEIGHT + 1];
    memset(*v, 0, (n + 1) * sizeof(*v));
    set<int> s;

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= MAX_WEIGHT; w++) {
            if (wt[i - 1] <= w) {
                int val = b[i - 1] + v[i - 1][w - wt[i - 1]];
                v[i][w] = val > v[i - 1][w] ? val : v[i - 1][w];
            } else {
                v[i][w] = v[i - 1][w];
            }
        }
    }

    // print_matrix(n + 1, MAX_WEIGHT + 1, (int *) v);
    return make_tuple(v[n][MAX_WEIGHT], s);
}

int main(int argc, char* argv[]) {
    int n = 5;
    int b[] = { 3, 5, 8, 4, 10 };
    int wt[] = { 2, 4, 5, 3, 9 };

    int max_value;
    set<int> s;
    tie(max_value, s) = knapsack(b, wt, n);

    cout << "Max value: " << max_value << endl;

    return 0;
}
