/*
N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 “좋다(GOOD)”고 한다.

N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라.

수의 위치가 다르면 값이 같아도 다른 수이다.

입력
첫째 줄에는 수의 개수 N(1 ≤ N ≤ 2,000), 두 번째 줄에는 i번째 수를 나타내는 Ai가 N개 주어진다. (|Ai| ≤ 1,000,000,000, Ai는 정수)

출력
좋은 수의 개수를 첫 번째 줄에 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;
int N;
int ans = 0;
vector<int> nums{};
void fun(int i) { // nums[i]를 만들 수 있는지 체크하는 함수
    for (int j = 0; j < N; ++j) {
        if(i == j) continue;
        int target = nums[i] - nums[j];
        int index = std::lower_bound(nums.begin(), nums.end(),target) - nums.begin();
        while(index < N && nums[index] == target) {
            if(index != i && index != j) {
                ans++;
                return;
            }
            index++;
        }

    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < N; ++i) {
        fun(i);
    }
    cout << ans;




}