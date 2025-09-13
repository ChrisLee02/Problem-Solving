#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search_index(vector<int> &a, int left, int right, int target)
{
    if (left > right)
        return -1;
        int mid = (left + right) / 2;
    if (a[mid] == target)
    {
        return mid;
    }

    else if (a[mid] < target)
    {
        return binary_search_index(a, mid + 1, right, target);
    }

    else
    {
        return binary_search_index(a, left, mid - 1, target);
    }
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,M, tmp;
    int index;
    int tmpindex;
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
        cout << upper_bound(nums1.begin(),nums1.end(),tmp) - lower_bound(nums1.begin(),nums1.end(),tmp) << " ";
    }
}