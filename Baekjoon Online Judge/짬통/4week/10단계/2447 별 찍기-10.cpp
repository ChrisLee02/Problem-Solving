/* https://www.acmicpc.net/problem/2447

재귀적인 패턴으로 별을 찍어 보자. N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.

크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.
***
* *
***
N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다. 예를 들어 크기 27의 패턴은 예제 출력 1과 같다.

입력
첫째 줄에 N이 주어진다. N은 3의 거듭제곱이다. 즉 어떤 정수 k에 대해 N=3k이며, 이때 1 ≤ k < 8이다.

출력
첫째 줄부터 N번째 줄까지 별을 출력한다. */
#include <iostream>
#include <cmath>

using namespace std;
void star(char **pic, int N, int r, int c)
{ // r과 c는 넣기 시작할 위치
    if (N == 3)
    {
        for (int i = 0; i < 3; i++)
            pic[r][c + i] = '*';

            pic[r + 1][c] = '*';
            pic[r + 1][c + 1] = ' ';
            pic[r + 1][c + 2] = '*';

        for (int i = 0; i < 3; i++)
            pic[r + 2][c + i] = '*';
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            star(pic, N / 3, r, c + N * i / 3);
        }
        star(pic, N / 3, r + N / 3, c);
        for (int i = r + N/3 ; i < r + N*2/3; i++)
        {
            for (int j = c + N / 3; j < c + N*2 / 3; j++)
            {
                pic[i][j] = ' ';
            }
        }
        star(pic, N / 3, r + N / 3, c + N * 2 / 3);
        
        for (int i = 0; i < 3; i++)
        {
            star(pic, N / 3, r+N*2/3, c + N * i / 3);
        }

    }
}

int main(void)
{
    int N;

    cin >> N;
    char **pic;
    pic = new char *[N];
    for (int i = 0; i < N; i++)
        pic[i] = new char[N];
    
    
            
    star(pic, N, 0, 0);
    for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << pic[i][j];
            }
            cout << endl;
        }
}


// for (int i = 0; i < N; i++)
//         for (int j = 0; j < N; j++)
//             pic[i][j] = '*';
//     for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 cout << pic[i][j];
//             }
//             cout << endl;
//         }

