/*
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
 */

#include <bits/stdc++.h>
#define Pair pair<int, int>


using namespace std;

int N;
vector<bool> updated{};
vector<int> seq{};
vector<vector<Pair>> tail_vec{}; // num, backtrack
vector<int> tail{};
vector<int> optimal{};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i<N; i++) {
        int tmp; cin >> tmp;
        seq.push_back(tmp);
    }
    tail.push_back(seq[0]);
    tail_vec.emplace_back();
    tail_vec.back().emplace_back(seq[0], -1);
    for(int i = 1; i<N; i++) {
        if(seq[i] > tail.back()) {
            tail.push_back(seq[i]);
            tail_vec.emplace_back();
            tail_vec.back().emplace_back(seq[i], (tail_vec.end()-2)->size() - 1);
        }
        else {
            int index = lower_bound(tail.begin(), tail.end(), seq[i]) - tail.begin();
            tail[index] = seq[i];
            tail_vec[index].emplace_back(seq[i], index==0 ? -1 : tail_vec[index-1].size() - 1);
        }
    }
    cout << tail.size() << '\n';
    int backtrack = 0;
    for (auto p = tail_vec.rbegin(); p != tail_vec.rend(); ++p) {
        vector<Pair> &tmp = *p;
        //cout << tmp[backtrack].first << " " << tmp[backtrack].second << endl;
        optimal.push_back(tmp[backtrack].first);
        backtrack = tmp[backtrack].second;
    }
    std::reverse(optimal.begin(), optimal.end());
    for(int i: optimal) {
        cout<< i << " ";
    }

}