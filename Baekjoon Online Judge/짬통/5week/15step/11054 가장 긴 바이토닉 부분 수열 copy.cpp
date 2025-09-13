/* https://www.acmicpc.net/problem/11054

수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.
예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 
{10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.
수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.
입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)
출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다. */

#include <iostream>
#include <string>   
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// nums[i]를 받아와서, 얘를 뒤집은 배열을 하나 더 만든다.
//각각에 대해 LIS를 생성해준 뒤
//인덱스 적당히 때려박으면 바이토닉 수열을 구할 수 있지 않을까?

void Make_LIS(int *nums, pair<int, int> **dp_increase, int N)
{
    int j, right0, right1;
    dp_increase[1][0] = make_pair(1, nums[1]);
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

        dp_increase[i][0] = make_pair(1, nums[i]);
        for (j = i - 1; j >= 1; j--)
        {

            if (j + 1 <= dp_increase[i][0].first)
                break;
            right0 = dp_increase[j][0].second;
            right1 = dp_increase[j][1].second;
            if (nums[i] > right0 && dp_increase[j][0].first + 1 > dp_increase[i][0].first)
            {
                dp_increase[i][0].first = dp_increase[j][0].first + 1;
            }
            if (nums[i] > right1 && dp_increase[j][1].first + 1 > dp_increase[i][0].first)
            {
                dp_increase[i][0].first = dp_increase[j][1].first + 1;
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
    Make_LIS(nums, dp_increase, N);
    Make_LIS(nums_reversed, dp_decrease, N);
    for(int i = 1; i<=N; i++) {
        int_tmp = max(dp_decrease[i][0].first + dp_increase[N-i+1][0].first - 1, dp_increase[i][0].first + dp_decrease[N-i+1][0].first - 1);
        if(Max<int_tmp) Max=int_tmp;
    }
    cout<<Max;
}
