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

vector<pii> adj[100001];


unordered_set<int> nodes{};


class comp {
public:
    bool operator()(pair<pii, int> &a, pair<pii, int> &b) {
        return a.second > b.second;
    }
};

priority_queue<pair<pii, int>, vector<pair<pii, int>>, comp> PQ{};

void prim() {
    int ans = 0;
    int cnt_edge = 0;
    nodes.insert(1);
    for(pii tmp: adj[1]){
        PQ.emplace(pii(1,tmp.first), tmp.second);
    }
    while(cnt_edge != N-1) {
        pair<pii, int> cur = PQ.top(); PQ.pop();
        if(nodes.find(cur.first.first) != nodes.end() && nodes.find(cur.first.second) != nodes.end()) {
            continue;
        }
        else {
            cnt_edge++;
           // cout << cur.first.first << " " << cur.first.second << " " << cur.second << endl;
            if(nodes.find(cur.first.first) == nodes.end()) {
                int node = cur.first.first;
                nodes.insert(node); ans += cur.second;
                for(pii tmp: adj[node]) {
                    if(nodes.find(tmp.first) != nodes.end()) continue;

                    PQ.emplace(pii(node,tmp.first), tmp.second);

                }
            }
            else {
                int node = cur.first.second;
                nodes.insert(node); ans += cur.second;
                for(pii tmp: adj[node]) {
                    if(nodes.find(tmp.first) != nodes.end()) continue;

                    PQ.emplace(pii(node,tmp.first), tmp.second);

                }

            }
        }



    }

    cout << ans;

}

int main()
{
    FastIO;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1].emplace_back(tmp2, tmp3);
        adj[tmp2].emplace_back(tmp1, tmp3);
    }

    prim();

}