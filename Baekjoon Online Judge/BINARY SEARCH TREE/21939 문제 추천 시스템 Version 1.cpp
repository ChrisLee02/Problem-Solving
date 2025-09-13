/*

 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;
int N, M;

bool comp(pii &a, pii &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}


unordered_map<int, int> prob_to_difficulty{};
set<pii> problem_set{}; // 난이도, 문제 번호


int main()
{
    FastIO;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        prob_to_difficulty[tmp1] = tmp2;
        problem_set.emplace(tmp2, tmp1);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string command; cin >> command;
        if(command == "recommend") {
            int x; cin >> x;
            if(x==1) {
                cout << (prev(problem_set.end()))->second << endl;
            } else {
                cout << problem_set.begin()->second << endl;
            }
        }
        else if (command == "add") {
            int P, L; cin >> P >> L;
            prob_to_difficulty[P] = L;
            problem_set.emplace(L, P);
        } else if (command == "solved") {
            int P; cin >> P;
            problem_set.erase(pii(prob_to_difficulty[P], P));
        }
    }
    


}