#include <iostream>

using namespace std;

int main(){
    int arr[9];
    for (int i = 0; i < 9; i++) {
        cin >> arr[i]; 
    }
    int max = 0;
    int tempi;
    for (int i = 0; i < 9; i++) {
        if (arr[i] > max) {
            max = arr[i];
            tempi = i + 1;
        }
    }

    cout << max << "\n" << tempi << endl;

    return 0;
}