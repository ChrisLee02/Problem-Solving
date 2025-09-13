/*
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은  = {10, 20, , 30, , 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다. 그러한 수열이 여러가지인 경우 아무거나 출력한다.
 */
//14002 가장 긴 증가하는 부분 수열 4
#include <bits/stdc++.h>

using namespace std;

int dp[1001]; // dp[i] = arr[i]로 끝나는 수열 중 최적
int arr[1001];
int backtrack[1001];
int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    dp[1] = 1;
    for (int i = 1; i <= N; ++i) {
        int Max = 0;
        for (int j = i-1; j >= 1; --j) {
            if(arr[j] < arr[i] && Max < dp[j] ) {
                backtrack[i] = j;
                Max = dp[j];
            }
        }
        dp[i] = Max + 1;
    }
    int ans = 0;
    int backtrack_index;
    for (int i = 1; i <= N; ++i) {
        if(dp[i] > ans) {
            ans = dp[i];
            backtrack_index = i;
        }
    }
    vector<int> vec{};
    while(backtrack_index != 0) {
        vec.push_back(arr[backtrack_index]);
        backtrack_index = backtrack[backtrack_index];
    }
    cout << ans << endl;
    for (auto i = vec.rbegin(); i != vec.rend(); i++) {
        cout << *i << " ";
    }

}