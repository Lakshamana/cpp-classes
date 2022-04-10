#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <pthread.h>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include <set>
#include <chrono>
#include<random>

using namespace std;

class Item {
    private:
        string class_name;
        double a, b, c, d;
    
    public:
        Item(double a, double b, double c, double d, string class_name) {
           this->a = a;
           this->b = b;
           this->c = c;
           this->d = d;
           this->class_name = class_name;
        }

        string get_class() {
            return class_name;
        }

        double get_a() {
            return a;
        }

        double get_b() {
            return b;
        }

        double get_c() {
            return c;
        }

        double get_d() {
            return d;
        }

        // euclidean distance
        double dist_to(Item& other) {
            return sqrt(pow((a - other.a), 2)
                    + pow((b - other.b), 2)
                    + pow((c - other.c), 2)
                    + pow((d - other.d), 2));
        }

        friend ostream& operator<<(ostream& os, Item& item) {
            char buf[43];
            sprintf(
                buf,
                "(%.f, %.f, %.f, %.f, %s)",
                item.a,
                item.b,
                item.c,
                item.d,
                item.class_name.c_str()
            );

            os << buf << endl;
            return os;
        }
};

vector<string> split(string s, char delim = ',') {
    stringstream ss(s);
    vector<string> words;

    while (ss.good()) {
        string buf;
        getline(ss, buf, delim);
        words.push_back(buf);
    }

    return words;
}

vector<Item> readlines(ifstream& ifs) {
    vector<Item> dataset;

    while (ifs.good()) {
        string buf;
        getline(ifs, buf);

        if (buf != "") {
            string class_name;
            double a, b, c, d;
            vector<string> line = split(buf);

            tie(a, b, c, d, class_name) = make_tuple(
                stod(line[0]),
                stod(line[1]),
                stod(line[2]),
                stod(line[3]),
                line[4]
            );

            dataset.push_back(Item(a, b, c, d, class_name));
        }
    }

    return dataset;
}

string knn(vector<Item>& items, Item& new_example, int k) {
    if (!(k % 2)) {
        k--;
        if (k <= 0) {
            k = 1;
        }
    }

    int items_size = items.size();
    set<pair<double, int>> dists;

    for (int i = 0; i < items_size; i++) {
        double dist = items[i].dist_to(new_example);
        dists.insert(make_pair(dist, i));
    }

    set<pair<double, int>>::iterator it;
    map<string, int> ctr = {
        make_pair("Iris-setosa", 0),
        make_pair("Iris-versicolor", 0),
        make_pair("Iris-virginica", 0),
    };

    int countK = 0;
    
    for (it = dists.begin(); it != dists.end(); it++) {
        string class_name = items[it->second].get_class();
        ctr[class_name]++;

        if (countK > k) break;
        countK++;
    }

    vector<pair<string, int>> pairs;
    for (pair<string, int> p : ctr) {
        pairs.push_back(p);
    }

    sort(pairs.begin(), pairs.end(), [](pair<string, int>& p1, pair<string, int>& p2) {
        return p1.second > p2.second;
    });

    return pairs.begin()->first;
}

int main(int argc, char* argv[]) {
    ifstream is("./dataset.csv");
    vector<Item> items = readlines(is);

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(items.begin(), items.end(), default_random_engine(seed));

    int training = 105;
    vector<Item> train_items;
    train_items.assign(items.begin(), items.begin() + training);

    vector<Item> test_items;
    test_items.assign(items.begin() + training, items.end());

    int accuracy = 0;
    int k = 5;

    for (Item& item : test_items) {
        string result_class_name = knn(train_items, item, k);
        if (result_class_name == item.get_class()) {
            accuracy++;
        }
    }

    int test_size = test_items.size();
    printf("Accuraccy: %.2f%% (%d/%d)", (double) 100 * accuracy / test_size, accuracy, test_size);

    return 0;
}
