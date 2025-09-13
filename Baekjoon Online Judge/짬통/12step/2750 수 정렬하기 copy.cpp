#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, tmp;
    cin >> N;
    vector<int> nums;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    sort(nums.begin(),nums.end());
    for(int i = 0; i < N; i++) {
        cout << nums[i] << '\n';
    }
}
