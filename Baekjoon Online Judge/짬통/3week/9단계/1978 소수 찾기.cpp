/* https://www.acmicpc.net/problem/1978
 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n) {
    int tmp = sqrt(n);
    if(n == 1) return false;
    for(int i = 2; i<n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int N, tmp;
    int count = 0;
    cin>>N;
    for(int i = 0; i<N; i++) {
        cin >> tmp;
        if(isPrime(tmp) ) count++;
    }
    cout << count;
}


