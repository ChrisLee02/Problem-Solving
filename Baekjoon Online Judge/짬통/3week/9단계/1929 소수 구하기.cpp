/* https://www.acmicpc.net/problem/1929

M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다. */
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

bool DynamicIsPrime(int n, vector<int> primes) {
    int tmp = sqrt(n);
    if(n == 1) return false;
    for(int i = 0; i<primes.size(); i++) {
        if(n%primes[i] == 0) {
            return false;
        }
    }
    return true;
}

int main(void){
    int M, N;
    cin >> M >> N;
    bool isPrimes[1000001];
    fill_n(isPrimes, 1000001,true);
    isPrimes[1] = false;
    for(int i = 1; i<=1000; i++) {
        if(isPrime(i)) {
            for(int j=2; j*i < 1000001; j++) {
            isPrimes[ j*i ]  = false;
        }
        }
    }


    for(int i = M; i<=N; i++) {
        if(isPrimes[i]) {
            cout << i << '\n';
        }
    }
    
    
}



