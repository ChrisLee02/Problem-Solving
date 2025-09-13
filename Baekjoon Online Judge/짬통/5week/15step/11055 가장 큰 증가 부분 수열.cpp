/* https://www.acmicpc.net/problem/11055

수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다. */

#include <iostream>
#include <string>   
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// nums[i]를 받아와서, 얘를 뒤집은 배열을 하나 더 만든다.
//각각에 대해 LIS를 생성해준 뒤
//인덱스 적당히 때려박으면 바이토닉 수열을 구할 수 있지 않을까?

void Make_BIS(int *nums, pair<int, int> **dp_increase, int N)
{
    int j, right0, right1;
    dp_increase[1][0] = make_pair(nums[1], nums[1]);
    dp_increase[1][1] = make_pair(0, -1);

    for (int i = 2; i <= N; i++)
    {
        if (dp_increase[i - 1][0].first == dp_increase[i - 1][1].first)
        {
            dp_increase[i][1] = (dp_increase[i - 1][0].second < dp_increase[i - 1][1].second) ? dp_increase[i - 1][0] : dp_increase[i - 1][1];
        }
        else
        {
            dp_increase[i][1] = (dp_increase[i - 1][0].first > dp_increase[i - 1][1].first) ? dp_increase[i - 1][0] : dp_increase[i - 1][1];
        }

        dp_increase[i][0] = make_pair(nums[i], nums[i]);
        for (j = i - 1; j >= 1; j--)
        {
            right0 = dp_increase[j][0].second;
            right1 = dp_increase[j][1].second;
            if (nums[i] > right0 && dp_increase[j][0].first + nums[i] > dp_increase[i][0].first)
            {
                dp_increase[i][0].first = dp_increase[j][0].first + nums[i];
            }
            if (nums[i] > right1 && dp_increase[j][1].first + nums[i] > dp_increase[i][0].first)
            {
                dp_increase[i][0].first = dp_increase[j][1].first + nums[i];
            }
        }
    }
}

int main(void) 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,j, right1, right0, int_tmp;
    cin >> N;
    // tuple<int,int,int> 짬통;
    // tuple<int,int,int> **dp_bitonic = new tuple<int,int,int>*[N+1]; 
    // dp[i][0/1] = int,int => 1번째~i번째까지 봤을 때 최적해 / i번째 포함미포함(0,1)
    // int, int,int  = 길이, 튜플 값, 가장 오른쪽의 값
    pair<int,int> **dp_increase = new pair<int,int>*[N+1]; // dp[i][0/1] = int,int => 1번째~i번째까지 봤을 때 최적해 / i번째 포함미포함(0,1)
    pair<int,int> **dp_decrease= new pair<int,int>*[N+1];
    int Max = 0;
    //int, int = 길이, 가장 오른쪽의 값
    int *nums = new int[N+1];
    int *nums_reversed = new int[N+1];
    for(int i = 1; i<=N; i++) {
        cin >> nums[i];
        nums_reversed[N-i+1] = nums[i];       
        dp_increase[i] = new pair<int,int>[2];
        dp_decrease[i] = new pair<int,int>[2];
    }
    Make_BIS(nums, dp_increase, N);
    
    cout << max(dp_increase[N][0].first, dp_increase[N][1].first);
}
