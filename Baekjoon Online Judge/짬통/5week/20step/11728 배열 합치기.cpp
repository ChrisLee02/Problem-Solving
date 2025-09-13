/* https://www.acmicpc.net/problem/11728
정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)

둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.

출력
첫째 줄에 두 배열을 합친 후 정렬한 결과를 출력한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, M, tmp,index1, index2;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    vector<int> nums1;
    vector<int> nums2;
    vector<int> sorted;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        nums1.push_back(tmp);
    }
    for(int i = 0; i < M; i++) {
        cin >> tmp;
        nums2.push_back(tmp);
    }
    index1 = 0;
    index2 = 0;
    while(index2<M && index1 < N) {
        if( nums1[index1] > nums2[index2] ) sorted.push_back(nums2[index2++]);
        else sorted.push_back(nums1[index1++]);
    }
    if(index2>=M) {
        while(index1 < N) sorted.push_back(nums1[index1++]);
    }
    else {
        while(index2 < M) sorted.push_back(nums2[index2++]);
    }
    for(int i = 0; i<sorted.size();i++) {
        cout << sorted[i] << " ";
    }
}
