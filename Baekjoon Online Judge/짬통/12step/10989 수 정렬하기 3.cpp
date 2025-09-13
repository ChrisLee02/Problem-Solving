//카운팅 정렬로 풀어야 하는 문제.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, tmp, Max = 10000;
    cin >> N;
    vector<int> nums;
    int *counting = new int[Max+1];
    fill_n(counting, Max+1, 0);
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        counting[tmp]++;
    }
    
    // for(int i = 0; i < Max; i++) {
    //     counting[i+1] += counting[i];
    // }
    // // for(int i = 0; i <= Max; i++) {
    //     cout << counting[i] << '\n';
    // }
    int prev = 0;
    for(int i = 0; i<=Max; i++) {
        while(counting[i] > 0 ) {
            cout << i << '\n';
            counting[i]--;
        }
    }
    // for(int i = 0; i<N; i++) {
    //     cout << sorted[i] << '\n';
    // }
}
