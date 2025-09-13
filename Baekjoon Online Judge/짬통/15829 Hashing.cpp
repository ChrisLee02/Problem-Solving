/* https://www.acmicpc.net/problem/15829
문제 혓바닥이 너무 길다.
 */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int r = 31;   
long long M = 1234567891;

long long powMod(int a, int n) {
    if(n==0) {
        return 1;
    }
    if(n==1) {
        return a%M;
    }
    else {
        if(n%2==1) {
            return (a%M)*powMod(a, n/2)*powMod(a, n/2);
        }
        else return powMod(a, n/2)*powMod(a, n/2);
    }
}

int main(void)
{
    int L;
     
    string alpha;
    long long sum = 0;
    long long x;
    cin >> L;
    cin >> alpha;
    x=1;
    for(int i = 0; i<L; i++) {
        sum = sum%M + ((alpha[i] - 'a' + 1)*(x%M));
        x = (x*31)%M; //31을 곱할 때 마다 나눠줘야 되는듯... 별도 함수로 접근하면 값이 커지나보다 씨이팔
    }
    cout << sum%M;
}
