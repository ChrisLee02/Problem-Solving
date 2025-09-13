// https://www.acmicpc.net/problem/11050


#include <iostream>
#include <cmath>

using namespace std;

int fac(int n) {
    if(n == 0) return 1;
    else return n*fac(n-1);
}

int main(void){
    int N,C;
    cin >> N >> C;
    cout << fac(N)/(fac(C)*fac(N-C)); 
}