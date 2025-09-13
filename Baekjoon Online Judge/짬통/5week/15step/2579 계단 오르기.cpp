/* https://www.acmicpc.net/problem/2579
계단 오르기 게임은 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임이다.

계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
마지막 도착 계단은 반드시 밟아야 한다.
따라서 첫 번째 계단을 밟고 이어 두 번째 계단이나, 세 번째 계단으로 오를 수 있다. 하지만, 첫 번째 계단을 밟고 이어
네 번째 계단으로 올라가거나, 첫 번째, 두 번째, 세 번째 계단을 연속해서 모두 밟을 수는 없다.

각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.

입력
입력의 첫째 줄에 계단의 개수가 주어진다.
둘째 줄부터 한 줄에 하나씩 제일 아래에 놓인 계단부터 순서대로 각 계단에 쓰여 있는 점수가 주어진다.
계단의 개수는 300이하의 자연수이고, 계단에 쓰여 있는 점수는 10,000이하의 자연수이다.

출력
첫째 줄에 계단 오르기 게임에서 얻을 수 있는 총 점수의 최댓값을 출력한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, K, tmp;
    cin >> N;
    vector<int> stairs;
    int **dp; // [i번째 계단][점수 최댓값 // 연속횟수] 
    dp = new int*[N+1];
    for(int i = 0; i<=N; i++) {
        dp[i] = new int[2];
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    stairs.push_back(0);
    for (int i = 1; i <= N; i++)
    {
        cin>>tmp;
        stairs.push_back(tmp);
    }
    if(N==1) {
        cout << stairs[1];
        return 0;
    }
    if(N==2) {
        cout << stairs[1] + stairs[2];
        return 0;
    }

    dp[1][0] = stairs[1];
    dp[1][1] = stairs[1];
    dp[2][0] = stairs[2]; //이차원 배열의 두번째 요소가 의미하는 바를 연속여부가 1일 때의 최댓값, 2일 때의 최댓값으로 각각 수정해야할 듯.
    dp[2][1] = stairs[1] + stairs[2];
    for (int i = 3; i <= N; i++)
    {
        dp[i][0] = max(dp[i-2][1] + stairs[i], dp[i-2][0] + stairs[i]); // 2칸 앞의 연속여부 2인 최댓값에 현재 계단값 더하기
        dp[i][1] = dp[i-1][0] + stairs[i]; // 1칸 앞의 연속여부 1인 최댓값에 현재 계단값 더하기
       
    }

    cout << max(dp[N][0], dp[N][1]);
}