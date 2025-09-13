/*
10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중,
 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다. 둘째 줄에는 수열이 주어진다.
 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.

출력
첫째 줄에 구하고자 하는 최소의 길이를 출력한다. 만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.
 */

#include <bits/stdc++.h>

using namespace std;

int N, S;
vector<int> seq{};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp; seq.push_back(tmp);
    }

    int i = 0;
    int j = 0;
    int sum = seq[i];
    int ans = 0x7fffffff;
    while(i < N && j < N) {
        if(sum >= S) {
            if(i==j) { // 더 탐색 안해도 된다. 이런 경우는 배제해버릴 겸
                cout<<1;
                return 0;
            } else {
                ans = min(ans, j - i + 1);
                sum -= seq[i];
                i++;
            }
        }
        else {
            j++;
            sum += seq[j];
        }
    }
    cout << ((ans == 0x7fffffff) ? 0 : ans);




}