#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, tmp, seq = 0;
    cin >> N;
    vector<int> nums1, nums2;
    map<int, int> compressed;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        nums1.push_back(tmp);
        nums2.push_back(tmp);
        compressed[tmp] = 0;
    }
    
    sort(nums1.begin(),nums1.end());
    
    for(int i = 0; i < N; i++) {
        compressed[nums1[i]] = seq;
        if(nums1[i] < nums1[i+1]) seq++;
    }
    for(int i = 0; i < N; i++) {
        cout << compressed[nums2[i]] << '\n';
    }
}