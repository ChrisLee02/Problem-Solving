#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    float tmp = sqrt(n);
    if(n == 1) return false;
    for(int i = 2; i<=tmp; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int main(void){
    int n;
    int count;
    while(1) {
        count = 0;
        cin >> n;
        if(n==0) {
            return 0;
        }
        for(int i = n+1; i<=2*n; i++) {
            if(isPrime(i)) {
                count++;
            }
        }
        cout << count << '\n';
    }
}