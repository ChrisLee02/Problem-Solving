/* https://www.acmicpc.net/problem/1629
문제 혓바닥이 너무 길다.
 */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long powMod(int a, int b, int c) {
    if(b==0) {
        return 1;
    }
    if(b==1) {
        return a%c;
    }
    else {
        if(b%2==1) {
            return ( (((a%c)*(powMod(a, b/2,c)%c))%c) * (powMod(a, b/2,c)%c) )%c;
        }
        else return ((powMod(a, b/2,c)%c)*(powMod(a, b/2,c)%c))%c;
    }
}

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << powMod(A,B,C);
}
