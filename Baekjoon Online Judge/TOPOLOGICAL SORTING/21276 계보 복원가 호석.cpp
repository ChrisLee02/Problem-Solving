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
//트리 형태에서 부모는 딱 하나이므로, 조상 개수를 따라서 배치해주면 될 듯함.
int N, M;

vector<int> adj[100001];
int in_degree[100001];
vector<int> result{};
unordered_map<string, int> name_to_id{};
unordered_map<int, string> id_to_name{};
map<string, set<string>> name_to_descendant_sorted{};


int main()
{
    FastIO;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        string tmp1; cin >> tmp1;
        name_to_id[tmp1] = i;
        id_to_name[i] = tmp1;
    }
    cin >> M;

    for (int i = 0; i < M; ++i) {
        string tmp1, tmp2; cin >> tmp1 >> tmp2;
        adj[name_to_id[tmp2]].push_back(name_to_id[tmp1]);
        in_degree[name_to_id[tmp1]]++;
    }
    queue<int> Q{};
    set<string> ancestor{};
    for (int i = 1; i <= N; ++i) {
        if(in_degree[i] == 0) {
            Q.push(i);
            ancestor.insert(id_to_name[i]);
        }
    }
    cout << ancestor.size() << endl;
    for(const string& s: ancestor) {
        cout << s << " ";
    }
    cout << endl;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        if(adj[cur].empty()) {
            name_to_descendant_sorted[id_to_name[cur]].emplace();
        }
        else {
            for(int child: adj[cur]) {
                if(in_degree[child] == in_degree[cur] + 1) {
                    name_to_descendant_sorted[id_to_name[cur]].insert(id_to_name[child]);
                    Q.push(child);
                }
            }
        }

    }

    for(auto &[key, key_set]: name_to_descendant_sorted) {
        if((*key_set.begin()).empty()) cout << key << " " << 0 << " " << endl;
        else {
            cout << key << " " << key_set.size() << " ";
            for(const string& s: key_set) {
                cout << s << " ";
            }
            cout << endl;
        }

    }




}