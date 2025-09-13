/* https://www.acmicpc.net/problem/1074

한수는 크기가 2^N × 2^N인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.
N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.
다음은 N=3일 때의 예이다.
입력
첫째 줄에 정수 N, r, c가 주어진다.

출력
r행 c열을 몇 번째로 방문했는지 출력한다.

1 ≤ N ≤ 15
0 ≤ r, c < 2N */

#include <iostream>
#include <cmath>
using namespace std;

void Z(int N, int a, int b, int r, int c, int *count) {
    if(N==2) {
        //cout << a << b << r << c <<endl;
        if(a==r && b==c) cout << *count;
        *count = *count + 1;
        if(a==r && b+1==c) cout << *count;
        *count = *count + 1;
        if(a+1==r && b==c) cout << *count;
        *count = *count + 1;
        if(a+1==r && b+1==c) cout << *count;
        *count = *count + 1;
    }
    else {
        //여기서 범위를 수학적으로 좁힌 뒤 일괄 count를 진행해야 할 듯
        if(r<a+N/2 && c<b+N/2) {
            Z(N/2, a,b,r,c,count);
        }
        if(r<a+N/2 && c>=b+N/2) {
            *count = *count + (N/2)*(N/2);
            Z(N/2, a,b+N/2,r,c,count);
        }
        if(r>=a+N/2 && c<b+N/2) {
            *count = *count + 2*(N/2)*(N/2);
            Z(N/2, a+N/2,b,r,c,count);
        }
        if(r>=a+N/2 && c>=b+N/2) {
            *count = *count + 3*(N/2)*(N/2);
            Z(N/2, a+N/2,b+N/2,r,c,count);
        }
        
    }
}

int main(void)
{
    int N, r, c;
    int count = 0;
    //int rcCount = 0;
    cin >> N >>r>>c;
    N = pow(2, N);
    //cout<<N;
    Z(N, 0, 0, r, c, &count);
}


