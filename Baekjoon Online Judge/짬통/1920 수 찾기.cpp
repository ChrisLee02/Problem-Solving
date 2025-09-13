#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N,M, tmp;
    cin >> N;
    vector<int> nums1;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        nums1.push_back(tmp);
    }
    sort(nums1.begin(),nums1.end());
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> tmp;
        cout << binary_search(nums1.begin(), nums1.end(), tmp) << '\n';
    }
}