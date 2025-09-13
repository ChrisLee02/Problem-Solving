/* https://www.acmicpc.net/problem/10872

0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(0 ≤ N ≤ 12)이 주어진다.

출력
첫째 줄에 N!을 출력한다. */
#include <iostream>
#include <cmath>

using namespace std;

int fac(int n) {
    if(n == 0) return 1;
    else return n*fac(n-1);
}

int main(void){
    int N;
    cin >> N;
    cout << fac(N);
}
