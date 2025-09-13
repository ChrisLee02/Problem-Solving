/* https://www.acmicpc.net/problem/11053

수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 30, 50} 이고, 길이는 4이다.
입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(void) 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,j;
    cin >> N;
    pair<int,int> tmp;
    pair<int,int> **dp = new pair<int,int>*[N+1]; // dp[i][0/1] = int,int => i번째~N번째까지 봤을 때 최적해 / i번째 포함미포함(0,1)
    //int, int = 길이, 가장 왼쪽의 값
    int *nums = new int[N+1];
    for(int i = 1; i<=N; i++) {
        cin >> nums[i];
        dp[i] = new pair<int,int>[2];
    }
    dp[N][0] = make_pair(1, nums[N]); // N~N까지 최적 부분수열은 길이가 1이고, 가장 왼쪽의 값은 nums[N]
    dp[N][1] = make_pair(0, 1001); // 1001이면 무조건 갱신되는 값임.
    for(int i = N-1; i>=1; i--) {
        if(dp[i+1][0].first == dp[i+1][1].first) {
            dp[i][1] = (dp[i+1][0].second > dp[i+1][1].second) ? dp[i+1][0]: dp[i+1][1];
        }
        else {
            dp[i][1] = (dp[i+1][0].first > dp[i+1][1].first) ? dp[i+1][0]: dp[i+1][1];
        }
        //i번째 요소를 미포함한다면, 바로 이전의 값에서, first값이 더 큰 놈으로 받아오면 됨.
        bool isUpdated = false;
        for (j = i + 1; j <= N; j++)
            {
                if (nums[i] >= dp[j][0].second && nums[i] < dp[j][1].second)
                { 
                    if(!isUpdated) {
                        dp[i][0] = make_pair(dp[j][1].first + 1, nums[i]);
                        isUpdated = true;
                    }
                    else if(dp[i][0].first-1 < dp[j][1].first) {
                        dp[i][0] = make_pair(dp[j][1].first + 1, nums[i]);
                    }

                }
                else if (nums[i] >= dp[j][1].second && nums[i] < dp[j][0].second )
                {
                    if(!isUpdated) {
                        dp[i][0] = make_pair(dp[j][0].first + 1, nums[i]);
                        isUpdated = true;
                    }
                    else if(dp[i][0].first-1 < dp[j][0].first) {
                        dp[i][0] = make_pair(dp[j][0].first + 1, nums[i]);
                    }
                    
                }
                else if(nums[i] < dp[j][0].second && nums[i] < dp[j][1].second)
                { // 둘 다 오름차순 조건 충족 시
                    if (dp[j][0].first == dp[j][1].first)
                    {
                        if (dp[j][0].second > dp[j][1].second)
                        {
                            if (!isUpdated)
                            {
                                dp[i][0] = make_pair(dp[j][0].first + 1, nums[i]);
                                isUpdated = true;
                            }
                            else if (dp[i][0].first - 1 < dp[j][0].first)
                            {
                                dp[i][0] = make_pair(dp[j][0].first + 1, nums[i]);
                            }
                        }
                        else {
                            if (!isUpdated)
                            {
                                dp[i][0] =make_pair(dp[j][1].first + 1, nums[i]);
                                isUpdated = true;
                            }
                            else if (dp[i][0].first - 1 < dp[j][0].first)
                            {
                                dp[i][0] = make_pair(dp[j][1].first + 1, nums[i]);
                            }
                        }
                    }
                    else
                    {
                        if (!isUpdated)
                            {
                                dp[i][0] = (dp[j][0].first > dp[j][1].first) ? make_pair(dp[j][0].first + 1, nums[i]) : make_pair(dp[j][1].first + 1, nums[i]);
                                isUpdated = true;
                            }
                            else if (dp[i][0].first - 1 < dp[j][0].first)
                            {
                                dp[i][0] =  (dp[j][0].first > dp[j][1].first) ? make_pair(dp[j][0].first + 1, nums[i]) : make_pair(dp[j][1].first + 1, nums[i]);
                            }
                    }
                }
            }
      // cout << dp[i][0].first <<" "<< dp[i][0].second << " " << dp[i][1].first << " "<< dp[i][1].second<<endl;
    } 
    cout << max(dp[1][0].first, dp[1][1].first);
    //사고 1. 수열을 증가하는 수열들의 단위로 분리한다면? -> 컷
    //사고 2. 역순으로 탐색한다면? 
    //1000개짜리 1~1000의 배열과 주어진 수열을 비교한다?
    //바로 연속되는 수열을 찾으면, 얘네는 최적해가 된다.
}
