#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 3, 4, 5};
    // int *p = &arr[0]; -> &*(p) -> p
    int *p = arr;
    // int **pp = &p;
    int i = 0;

    while (i < 5) {
        cout << *p << endl;
        // cout << **pp << endl; // segmentation fault - non continuous index for pp
        p++;
        // pp++;
        i++;
    }

    return 0;
}
