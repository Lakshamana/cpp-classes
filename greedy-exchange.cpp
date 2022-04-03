#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

vector<int> greedy_exchange(vector<int>& coins, int value) {
    vector<int> result;
    sort(coins.begin(), coins.end());

    int i = coins.size() - 1;
    while (i >= 0) {
        int coin = coins.at(i);
        if (coin > value) {
            i--;
            continue;
        };

        if (value >= coin) {
            value -= coin;
            result.push_back(coin);
        }

        if (!value) return result;
        if (coin > value) i--;
    }

    return result;
}

int main (int argc, char* argv[]) {
    vector<int> coins = { 1, 2, 5, 10, 20, 50 };

    vector<int> result = greedy_exchange(coins, 226);

    cout << "Used coins: ";
    for (int item : result) {
        cout << item << " ";
    }

    return 0;
}
