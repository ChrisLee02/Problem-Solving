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

void LCS2(pair<int, int> **dp, string s1, string s2) {
    // 당장 +1하는것보다, 앞으로 돌아가는 쪽이 더 최적해일 수 있다.
    // 바로 이전의 오른쪽 값을 기준으로 그 앞에서 다시 시작할지, 그 뒤를 이어갈지로 0과 1을 나누냐?
    int N1 = s1.length();
    int N2 = s2.length();
    int right0,right1,j;
    dp[0][1] = make_pair(0, -1);
    if(s2.find(s1[0], 0) == string::npos) {
        dp[0][0] = make_pair(0, -1);
    } else {
        dp[0][0] = make_pair(1, s2.find(s1[0],0));
    }
   
    for(int i = 1;i<N1;i++) {
        if(dp[i-1][0].first == dp[i-1][1].first) {
            dp[i][1] = (dp[i-1][0].second < dp[i-1][1].second) ? dp[i-1][0]: dp[i-1][1];
            // 문자열 길이가 같다면, 가장 오른쪽 값이 작은 놈이 더 유리함
        }
        else {
            dp[i][1] = (dp[i-1][0].first > dp[i-1][1].first) ? dp[i-1][0]: dp[i-1][1];
            // 길이가 같지 않으면 수열 길이로 판단
        }
        if(s2.find(s1[i], 0) == string::npos) {
            dp[i][0] = make_pair(0, -1); // 존재 안하면 앞에 탐색할 이유가 없음
        } 
        else {
            dp[i][0] = make_pair(1, s2.find(s1[i],0));// dp[i][0]의 기본값 설정.
            for (j = i - 1; j >= 0; j--)
            {
                // 현재 수열 길이랑, j의 위치를 비교하면 break조건,continue조건 검토 가능
                if (j + 2 <= dp[i][0].first)
                    break;
                // j의 위치 + 1 = dp[j]에서 나올 수 있는 길이 값의 상한선
                
                right0 = dp[j][0].second;
                right1 = dp[j][1].second; //바로 이전의 두 최적해에서 가장 오른쪽 값의 인덱스를 가져옴.
                if (right0<s2.size()-1 && s2.find(s1[i], right0+1) != string::npos && dp[j][0].first + 1 > dp[i][0].first)
                { //가장 오른쪽 값의 인덱스보다 오른쪽에서 s1[i]가 존재 & 길이 갱신조건 만족 && right값이 맨 끝 인덱스보다 작아야됨.
                    dp[i][0].first = dp[j][0].first + 1;
                    dp[i][0].second = s2.find(s1[i], right0+1);
                   // cout << dp[i][0].first <<" "<< dp[i][0].second << endl;
                }
                
                if (right1<s2.size()-1 && s2.find(s1[i], right1+1) != string::npos && dp[j][1].first + 1 > dp[i][0].first)
                { //
                    dp[i][0].first = dp[j][1].first + 1;
                    dp[i][0].second = s2.find(s1[i], right1+1);
                    //cout << dp[i][0].first <<" "<< dp[i][0].second << endl;
                }           
            }
        }
     //   cout << dp[i][0].first <<" "<< dp[i][0].second << " " << dp[i][1].first << " "<< dp[i][1].second<<endl;
    }
}

void LCS(int **dp, string s1, string s2, vector<int> *posInString2, int *Max) {
    // 당장 +1하는것보다, 앞으로 돌아가는 쪽이 더 최적해일 수 있다.
    //dp[i][j] => i가 j에 대응될 때, 0~i까지에서의 최적해
    int i, j;
    int N1 = s1.length();
    int N2 = s2.length();
    for(int j = 0; j<posInString2[s1[0]-'A'].size(); j++) {
            dp[0][ posInString2[s1[0]-'A'][j] ] = 1;
            *Max = 1;
    }

    for(int i = 1; i<N1; i++) {
        for(int j = 0; j<posInString2[s1[i]-'A'].size(); j++) {
            dp[i][ posInString2[s1[i]-'A'][j] ] = 1;
            for(int l = i-1; l>=0;l--){
                if(l+2 < dp[i][ posInString2[s1[i]-'A'][j] ] ) break;
                for(int k = 0; k<posInString2[s1[l]-'A'].size(); k++) {
                if(  posInString2[s1[i]-'A'][j] <= posInString2[s1[l]-'A'][k] ) break;
                if( dp[i][ posInString2[s1[i]-'A'][j] ] < dp[l][ posInString2[s1[l]-'A'][k] ] + 1 ) {
                    dp[i][ posInString2[s1[i]-'A'][j] ] = dp[l][ posInString2[s1[l]-'A'][k] ] + 1;
                    if(dp[i][ posInString2[s1[i]-'A'][j] ] > *Max) *Max = dp[i][ posInString2[s1[i]-'A'][j] ];
                }
            }
            }
            
        }
    }
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
