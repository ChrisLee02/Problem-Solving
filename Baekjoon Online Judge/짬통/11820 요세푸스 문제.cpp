#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//환형 큐를 이용해야 하나..?

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N,M,K,tmp;
    cin >> N >> K;
    queue<int> nums1;
    queue<int> joseph;
    for(int i = 1; i <= N; i++) {
        nums1.push(i);
    }
    for(int i = 0; i<N; i++) {
        int seq = 1;
        while(1) {
            if(seq==K) break;
            nums1.push(nums1.front());
            nums1.pop();
            seq++;
        }
        joseph.push(nums1.front());
        nums1.pop();
    }
    cout << "<";
    for(int i = 0; i < N-1; i++) {
        cout << joseph.front() << ", " ;
        joseph.pop();
    }
    cout << joseph.front()<<">";
}