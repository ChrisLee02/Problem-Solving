/* https://www.acmicpc.net/problem/9184
재귀 호출만 생각하면 신이 난다! 아닌가요?

다음과 같은 재귀함수 w(a, b, c)가 있다.

if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
위의 함수를 구현하는 것은 매우 쉽다. 하지만, 그대로 구현하면 값을 구하는데 매우 오랜 시간이 걸린다. (예를 들면, a=15, b=15, c=15)

a, b, c가 주어졌을 때, w(a, b, c)를 출력하는 프로그램을 작성하시오.

입력
입력은 세 정수 a, b, c로 이루어져 있으며, 한 줄에 하나씩 주어진다. 입력의 마지막은 -1 -1 -1로 나타내며, 세 정수가 모두 -1인 경우는 입력의 마지막을 제외하면 없다.

출력
입력으로 주어진 각각의 a, b, c에 대해서, w(a, b, c)를 출력한다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
//#include <format>

using namespace std;

int w(int a, int b, int c, int ***dp)
{
    int sum = 0;
    if(dp[a][b][c] != 0) return dp[a][b][c];    
    if (a <= 50 || b <= 50 || c <= 50)
    {
        return 1;
    }
    if (a > 70 || b > 70 || c > 70)
    {
       dp[a][b][c] = w(70, 70, 70,dp);
       return dp[a][b][c];
    }
    if (a < b && b < c)
    {
        dp[a][b][c] = w(a, b, c - 1,dp) + w(a, b - 1, c - 1,dp) - w(a, b - 1, c,dp);
        return dp[a][b][c];
    }
    dp[a][b][c] = w(a - 1, b, c,dp) + w(a - 1, b - 1, c,dp) + w(a - 1, b, c - 1,dp) - w(a - 1, b - 1, c - 1,dp);
    return dp[a][b][c];
}




int main(void)
{
    int N, a, b, c, tmp, i, j, k;
    string str;
    //int dp[101][101][101];
    int ***dp = new int**[101];
    for( i = 0; i<=100; i++) {
        dp[i] = new int*[101];
    }
    for( i = 0; i<=100; i++) {
        for( j = 0; j<=100; j++) {
            dp[i][j] = new int[101];
        }
       
    }
    for( i = 0; i<=100; i++) {
        for( j = 0; j<=100; j++) {
            for( k = 0; k<=100; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    while (1)
    {
        cin >> a >> b >> c;
        //str = format("w({}, {}, {}) = ",a,b,c);
        if (a == -1 && b == -1 && c == -1)
            break; 
        else cout << "w("<<a<< ", "<<b<< ", "<<c<< ") = " << w(a+50,b+50,c+50,dp) << '\n';
    }
}



/* a = 51;
    b = 51;
    c = 51;
    i = 0;
    while (a <= 100 && b <= 100 && c <= 100)
    {
        if (a > 70 || b > 70 || c > 70)
        {
            dp[a][b][c] = dp[70][70][70];
            if (i % 3 == 0)
            {
                a++;
            }
            if (i % 3 == 1)
            {
                b++;
            }
            if (i % 3 == 2)
            {
                c++;
            }
            i++;
            continue;
        }
        if (a < b && b < c)
        {
            dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
            if (i % 3 == 0)
            {
                a++;
            }
            if (i % 3 == 1)
            {
                b++;
            }
            if (i % 3 == 2)
            {
                c++;
            }
            i++;
            continue;
        }
        dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
        if (i % 3 == 0)
        {
            a++;
        }
        if (i % 3 == 1)
        {
            b++;
        }
        if (i % 3 == 2)
        {
            c++;
        }
        i++;      
    } */