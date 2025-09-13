#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a = -1;
    int temp = n;
    int count = 0;
    while (n != a) {
        a = (temp % 10) * 10 + (temp / 10 + temp % 10) % 10;
        temp = a;
        count++;
    }

    cout << count << endl;
}