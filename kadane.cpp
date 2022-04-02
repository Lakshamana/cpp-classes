#include <iostream>
#include <vector>

using namespace std;

int kadane(vector<int>& v) {
  int curr_max = 0, total_max = -1;
  int size_v = v.size();
  for (int i = 0; i < size_v; ++i) {
    curr_max += v[i];
    if (curr_max < 0)
      curr_max = 0;
    if (curr_max > total_max)
      total_max = curr_max;
  }
  return total_max;
}

int main(int argc, char *argv[]) {
  vector<int> v { -2, 5, -1, 2, -3 };

  cout << "Max sum of numbers: " << kadane(v) << '\n';
  return 0;
}
