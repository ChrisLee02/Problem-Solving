/*
상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 상덕이는 가방을 K개 가지고 있고,
각 가방에 담을 수 있는 최대 무게는 Ci이다. 가방에는 최대 한 개의 보석만 넣을 수 있다. 상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)
다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)
다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)
모든 숫자는 양의 정수이다.

출력
첫째 줄에 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다.
 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define value first
#define weight second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;

int N, K;
vector<pii> gems{};
multiset<int> bags{};

int main()
{
    FastIO;
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        gems.emplace_back(tmp2, tmp1); // value,
    }

    for (int i = 0; i < K; ++i) {
        int tmp; cin >> tmp;
        bags.insert(tmp);
    }

    std::sort(gems.begin(), gems.end());

    long long ans = 0;
    for (auto p = gems.rbegin(); p != gems.rend(); ++p) {
        auto bag_loc = bags.lower_bound(p->second);
        if(bag_loc != bags.end()) {
            //cout << *bag_loc << " "<< p->first << endl;
            ans += p->first;
            bags.erase(bag_loc);
        }
    }
    cout << ans;
}