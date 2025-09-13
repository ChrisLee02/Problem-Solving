#include <iostream>

using namespace std;

int main() {
    int max = -100000000;
    int min = 100000000;
    int num_of_int;
    cin >> num_of_int;
    int *list = new int[num_of_int];
    for (int i = 0; i < num_of_int; i++) {
        cin >> list[i];
    }
    for (int i = 0; i < num_of_int; i++) {
        if (list[i] < min) {
            min = list[i];
        }
        if (list[i] > max) {
            max = list[i];
        }
    }

    delete[] list;

    cout << min << " " << max << endl;
}