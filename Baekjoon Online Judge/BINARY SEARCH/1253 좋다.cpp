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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> nums{};
    vector<int> nums_without_zero{};
    int zero_count = 0;
    vector<int> x_plus_y{};
    vector<int> x_plus_y_without_zero{};
    map<int, set<int>> x_plus_y_set{};
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
        if(tmp==0) zero_count++;
    }
    std::sort(nums.begin(), nums.end());
    /*int ans = 0;
    for (int i = 0; i < N-1; ++i) {
        for (int j = i+1; j < N; ++j) {
            int target = nums[i] + nums[j];
            int count = std::upper_bound(nums.begin(), nums.end(), target) - std::lower_bound(nums.begin(), nums.end(), target);
            if(target == nums[i]) count--;
            if(target == nums[j]) count--;
            ans += count;
        }
    }
    cout << ans;*/ //보류


    /*for (int i = 0; i < nums_without_zero.size()-1; ++i) {
        for (int j = i+1; j < nums_without_zero.size(); ++j) {
            x_plus_y_without_zero.push_back(nums_without_zero[i] + nums_without_zero[j]);
        }
    }*/

    for (int i = 0; i < nums.size()-1; ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            if(nums[i] == 0 && nums[j] == 0) {
                if(zero_count >= 3) {
                    x_plus_y.push_back(0);
                }
            }
            else if(nums[i] == 0) {// 한쪽이 0인 경우에는 나머지 한 쪽의 숫자에 해당하는 개수가 2개 이상이어야 한다.
                if(std::upper_bound(nums.begin(), nums.end(),nums[j]) - std::lower_bound(nums.begin(), nums.end(),nums[j]) >= 2) {
                    x_plus_y.push_back(nums[i] + nums[j]);
                }
            }
            else if(nums[j] == 0) {
                if(std::upper_bound(nums.begin(), nums.end(),nums[i]) - std::lower_bound(nums.begin(), nums.end(),nums[i]) >= 2) {
                    x_plus_y.push_back(nums[i] + nums[j]);
                }
            }
            else x_plus_y.push_back(nums[i] + nums[j]);
        }
    }


    std::sort(x_plus_y.begin(), x_plus_y.end());
    x_plus_y.erase(std::unique(x_plus_y.begin(), x_plus_y.end()), x_plus_y.end());
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if(std::binary_search(x_plus_y.begin(), x_plus_y.end(),nums[i])) ans++;
    }

    cout << ans;

    // 0을 포함한 상태의 답. -> 이러면 0 4 4 같은 경우를 못잡는다.




}