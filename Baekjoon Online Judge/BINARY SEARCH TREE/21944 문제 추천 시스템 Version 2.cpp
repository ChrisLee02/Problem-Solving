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
unordered_map<int, int> prob_to_algorithm{};

unordered_map<int, set<pii>> problem_set_by_algo{}; // 난이도, 문제 번호
set<pii> problem_set_all{};

int main()
{
    FastIO;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int P, L, G; cin >> P >> L >> G; // P, L, G
        prob_to_difficulty[P] = L;
        prob_to_algorithm[P] = G;
        problem_set_all.emplace(L, P);
        problem_set_by_algo[G].emplace(L, P);

    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string command; cin >> command;
        if(command == "recommend") {
            int G, x; cin >> G >> x;
            if(x==1) {
                cout << (prev(problem_set_by_algo[G].end()))->second << endl;
            } else {
                cout << problem_set_by_algo[G].begin()->second << endl;
            }
        }

        else if(command == "recommend2") {
            int x; cin >> x;
            if(x==1) {
                cout << (prev(problem_set_all.end()))->second << endl;
            } else {
                cout << problem_set_all.begin()->second << endl;
            }
        }

        else if(command == "recommend3") {
            int x, L; cin >> x >> L;
            auto p = problem_set_all.lower_bound(pii(L,0));
            if(x==1) {
                if(p == problem_set_all.end()) cout << -1 << endl;
                else cout << p->second << endl;
            } else {
                if(p==problem_set_all.begin()) cout << -1 << endl;
                else cout << (prev(p))->second << endl;
            }
        }

        else if (command == "add") {
            int P, L, G; cin >> P >> L >> G; // P, L, G
            prob_to_difficulty[P] = L;
            prob_to_algorithm[P] = G;
            problem_set_all.emplace(L, P);
            problem_set_by_algo[G].emplace(L, P);
        } else if (command == "solved") {
            int P; cin >> P;
            problem_set_by_algo[prob_to_algorithm[P]].erase(pii(prob_to_difficulty[P], P));
            problem_set_all.erase(pii(prob_to_difficulty[P], P));
        }
    }



}