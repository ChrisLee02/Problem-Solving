/* https://www.acmicpc.net/problem/9251

LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다. */

#include <iostream>
#include <string>   
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

void LCS(int **dp, string s1, string s2, vector<int> *posInString2, int *Max) {
    // dp[i][j] s1을 0~i까지, s2를 0~j까지 볼 때 최적해
    // 이때 s1[i] == s2[i] dp[i][j] = dp[i-1][j-1] + 1
    //아니면? dp[i][j] = s1을 한 칸 물리든가 s2를 한칸 내려서 둘 중에 최적해
}



int main(void) 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    string s1, s2;
    cin >> s1 >> s2;
    int right0,right1,j;
    int N1 = s1.length();
    int N2 = s2.length();
    int **dp_1 = new int*[N1];
    vector<int> posInString2[26];//알파벳 위치를 오름차순으로 담을 벡터배열
    //dp[i][0/1] => 0~i-1번째까지에서, i번째 포함/미포함 시 각각의 최적 길이와 맨 오른쪽 인덱스(빈 문자열은 -1로 할당 => i+1부터 일관적인 코드) 문자열 특성 상, 0~i-1로 구현함.
    for(int i = 0; i<N1; i++) {
        dp_1[i] = new int[N2];
    }
    for(int i = 0; i<N1; i++) {
        for(int j = 0; j<N2; j++) {
            dp_1[i][j] = 0;
        }
    }
    for(int i = 0; i<N2; i++) {
        posInString2[s2[i] - 'A'].push_back(i);
    }
    int Max = 0;
    LCS(dp_1, s1, s2, posInString2, &Max);
    
    // for (int i = 0; i < N1; i++)
    // {
    //     cout << dp_1[i][0].first <<" "<< dp_1[i][0].second << " " << dp_1[i][1].first << " "<< dp_1[i][1].second<<endl;
    // }
    // cout << endl;
    // for (int i = 0; i < N2; i++)
    // {
    //     cout << dp_2[i][0].first <<" "<< dp_2[i][0].second << " " << dp_2[i][1].first << " "<< dp_2[i][1].second<<endl;
    // }
    cout << Max;
}
