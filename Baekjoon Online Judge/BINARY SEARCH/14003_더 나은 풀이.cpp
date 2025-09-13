/*
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
 */

//출처: https://www.acmicpc.net/source/62446155

#include <bits/stdc++.h>
using namespace std;

int n, a[1010101];
vector<int> arr; // 이분 탐색을 통해 arr[i-1]에는 length i의 부분 수열의 끝자리 중 최솟값이 들어가도록 한다.
int idx[1010101]; // a의 숫자들에 붙이는 번호로, 해당 숫자가 속할 수 있는 부분 수열 중 가장 긴 부분 수열에서 해당 숫자가 몇 번째인지를 나타냄.

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    // input
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    arr.push_back(a[1]);
    idx[1] = 1;
    for (int i = 2; i<=n; ++i) {
        if(a[i] > arr.back()) {
            arr.push_back(a[i]);
            idx[i] = arr.size();
        }
        else {
            int index = std::lower_bound(arr.begin(), arr.end(),a[i]) - arr.begin();
            arr[index] = a[i];
            idx[i] = index + 1;
        }
    } // idx값을 추가하는 부분만 제외하면 이분 탐색을 이용한 풀이와 동일함.

    int ans = arr.size();

    cout << ans << '\n';
    vector<int> optimal{};
    // idx의 정의에 따라, 만약 i<j이고 idx[i] < idx[j]면 a[i]와 a[j]는 최적 부분 수열을 공유한다.
    for (int i = n; i >= 1; --i) {
        if(idx[i] == ans) {
            optimal.push_back(a[i]);
            ans--;
        }
    }
    std::reverse(optimal.begin(), optimal.end());
    for(int i: optimal) {
        cout << i << " ";
    }
}