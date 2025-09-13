#include <iostream>

using namespace std;

int main() {
    int arr[10];
    int ex[10] = {43, 43, 43, 43, 43, 43, 43,43,43,43};
    int n;
    int count = 0;
    for (int i = 0; i < 10; i++) {
        cin >> n;
        arr[i] = n % 42;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i] == ex[j]) {
                break;
            }
            if ( j == 9){
                count++;
                ex[i] = arr[i];
            }        
        }
    }

    cout << count << endl;
}