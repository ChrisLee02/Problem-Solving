/* https://www.acmicpc.net/problem/12865
이 문제는 아주 평범한 배낭에 관한 문제이다.

한 달 후면 국가의 부름을 받게 되는 준서는 여행을 가려고 한다. 세상과의 단절을 슬퍼하며 최대한 즐기기 위한 여행이기 때문에, 가지고 다닐 배낭 또한 최대한 가치 있게 싸려고 한다.

준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 아직 행군을 해본 적이 없는 준서는 최대 K만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다. 준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.

입력
첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000)가 주어진다. 두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게 W(1 ≤ W ≤ 100,000)와 해당 물건의 가치 V(0 ≤ V ≤ 1,000)가 주어진다.

입력으로 주어지는 모든 수는 정수이다.

출력
한 줄에 배낭에 넣을 수 있는 물건들의 가치합의 최댓값을 출력한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
    long long N,K,tmp1, tmp2, W,V;
    cin >> N >> K;
    pair<int, int> *items = new pair<int, int>[N+1];
    vector<int> existWeight;
    // pair<int, int> **dp = new pair<int, int>*[N+1];  // 0~i번째까지에서, i번째 요소 포함/미포함, <무게, 가치>
    long long **dp = new long long*[101];
    for(int i = 1; i<=100;i++) {
        dp[i] = new long long[100001];
        fill_n(dp[i], 100001, 0);
    } 
    int Max = 0;
    //음.. dp[W] = V 로도 가능할 것 같은데
    // dp[W][V] = 0으로 초기화 후, 기존 값보다 크면 덮어쓰는 방식으로 ㄱㄱ
    // 덮어쓰니까 안되는거야 ㅣㅇ 씨발새끼야
    // dp[i][W] = V로 갑시다.
    for(int i = 1; i<=N; i++) {
        cin >> tmp1 >> tmp2;
        items[i] = make_pair(tmp1, tmp2);
    }
   
    //cout<<endl;
    existWeight.push_back(0);
    if(items[1].first > K) {
        Max = 0;
    }
    else {
        dp[1][items[1].first] = items[1].second;
        existWeight.push_back(items[1].first);
        Max = items[1].second;
    }
    // dp[1][items[1].first] = items[1].second;
    // existWeight.push_back(items[1].first);
    // existWeight.push_back(0);
    // Max = items[1].second;
    

    //cout << endl;
    
    for(int i = 2; i<=N; i++) {
        W = items[i].first;
        V = items[i].second;
        tmp1 = existWeight.size(); //tmp1은 존재하는 무게의 사이즈 , tmp2는 그걸 순회하는 인덱스
        // if(tmp1 != 0) cout << existWeight[tmp1-1] << ":" << dp[i][existWeight[tmp1-1]] <<endl;
        // cout <<"i: " << i << " " << W << " " << V<<endl;
        // for(int j = 0; j<existWeight.size(); j++) {
        //     cout << existWeight[j] << ":" << dp[i-1][existWeight[j]] <<endl;
        // }
        // cout << endl;
        if( W > K ) continue;
        for(int j = 0; j<tmp1;j++) {
            tmp2 = existWeight[j];
            dp[i][tmp2] = dp[i-1][tmp2];
        }
        if(W <= K ) {
            if( dp[i-1][W] > V ) {
                dp[i][W] = dp[i-1][W];
            }
            else{
                if( dp[i][W] == 0) {
                    existWeight.push_back(W);
                }
                dp[i][W] = V;
                if(dp[i][W]>Max) Max = dp[i][W];
            }  
        }
        
        //cout << tmp1 << endl;
        for(int j = 0; j<tmp1;j++) {
            tmp2 = existWeight[j];
            if(W+tmp2 <= K ) {
                if( dp[i-1][W+tmp2] > dp[i-1][tmp2] + V ) {
                    dp[i][W+tmp2] = dp[i-1][W+tmp2];
                }
                //cout << W << " " << V << endl;
                else {
                    if(dp[i][W+tmp2] == 0 ) {
                        existWeight.push_back(W+tmp2);
                    }
                    dp[i][W+tmp2] = dp[i-1][tmp2] + V;

                    if(dp[i][W+tmp2]>Max) Max = dp[i][W+tmp2];
                }
                

                
            }
        }
    }
    // for(int i = 0; i<existWeight.size(); i++) {
    //     cout << existWeight[i] << ":" << dp[N][existWeight[i]] <<endl;
    // }
    // tmp1 = existWeight.size();
    // if(tmp1 != 0) cout << existWeight[tmp1-1] << ":" << dp[N][existWeight[tmp1-1]] <<endl;
    // cout << endl;
    
    cout << Max;
}