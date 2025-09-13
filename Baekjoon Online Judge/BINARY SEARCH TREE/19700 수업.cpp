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
int N;

vector<pii> students{}; //이건 k,h로 두고
multiset<int> teams{};  // 팀의 사이즈 수만 저장



// 속좁은 새끼들부터 집어넣는다.
// 왜냐면 이왕 깔아준다면, 속이 넓은 친구가 속이 좁은 친구의 밑에 있는게 더 효율적이기 때문.
// =============================
// 키 큰 새끼들부터 넣으면, 지금 넣는 애만 괜찮은지 체크하면 됨. 나머지는 ㅈ까라하시고
// 집합을 보관할 이유가 없다. 그냥 개수만 저장하면 된다.
int main() {
    FastIO;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int h, k;
        cin >> h >> k;
        students.emplace_back(h, k);
    }
    std::sort(students.begin(), students.end());
    std::reverse(students.begin(), students.end());
    teams.insert(1);
    for (int i = 1; i < N; ++i) {

        int k = students[i].second;
        // 가능한 딱코로 들어가는게 최적이니까, lowerbound 이용해야할 듯

        auto p = teams.lower_bound(k);
        if(p == teams.begin()) {
            // cout << "case1: " << student.first << " " << student.second << endl;
            teams.insert(1);
        }
        else{
            // cout << "case2: " << student.first << " " << student.second << endl;
            int tmp = *prev(p);
            teams.erase(prev(p));
            teams.insert(tmp+1);
        }

    }


    cout << teams.size();
    /*for(int i: teams) {
        cout << i << " ";
    }
    cout<<endl;*/

}