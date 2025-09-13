/* https://www.acmicpc.net/problem/1463
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

입력
첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.

출력
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int fx(int x) {
    if(x%3 == 0) return x/3;
    if(x%2 == 0) return x/2;
    else return x-1;
}

int makeOne(int x, int *dp) {
    int x3,x2,x1,tmp;
    if(dp[x] != -1) {
        return dp[x];
    }
    if(x%3==0 && x%2 == 0) {
        x1 = makeOne(x-1, dp);
        x2 = makeOne(x/2, dp);
        x3 = makeOne(x/3, dp);
       // cout << x1 << " " << x3 << endl;
        if( x1 >= x3 && x2 >= x3 ) dp[x] = 1 + x3;
        if( x1 >= x2 && x3 >= x2 ) dp[x] = 1 + x2;
        if( x2 >= x1 && x3 >= x1 ) dp[x] = 1 + x1;
        return dp[x];
    }

    if(x%3==0) {
        x1 = makeOne(x-1, dp);
        x3 = makeOne(x/3, dp);
       // cout << x1 << " " << x3 << endl;
        if(x1 > x3) dp[x] = 1 + x3;
        else dp[x] = 1 + x1;
        return dp[x];
    }
    if(x%2==0) {
        x1 = makeOne(x-1, dp);
        x2 = makeOne(x/2, dp);
       // cout << x1 << " " << x2 << endl;
        if(x1 > x2) dp[x] = 1 + x2;
        else dp[x] = 1 + x1;
        return dp[x];
    }
        dp[x] = 1 + makeOne(x-1, dp);
        return dp[x];
    
}


int main(void)
{
    int N, tmp;
    int count = 0;
    cin >> N;
    int *dp = new int[N+1];
    fill_n(dp, N+1, -1);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    cout << makeOne(N, dp) << endl;
    // for(int i = 1; i<=N; i++) {
    //     cout << makeOne(i, dp) << endl;
    // }
}
