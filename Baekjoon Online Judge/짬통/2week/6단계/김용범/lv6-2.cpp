#include <iostream>


int d(int n) {
    int x = n + n / 1000 + (n % 1000) / 100 + (n % 100) / 10 + n % 10;

    return x;
}

int main(){
    int arr[10000];
    for (int i = 0; i < 10000; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < 10000; i++){
        for (int j = 0; j < 10000; j++) {
            if ( arr[i] == d(j) ){
                break;
            }
            if (j == 9999) {
                std::cout << arr[i] << std::endl;
            }
        }
    }
}