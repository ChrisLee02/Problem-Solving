/*
상욱 조교는 동호에게 N개의 문제를 주고서, 각각의 문제를 풀었을 때 컵라면을 몇 개 줄 것인지 제시 하였다. 하지만 동호의 찌를듯한 자신감에 소심한
 상욱 조교는 각각의 문제에 대해 데드라인을 정하였다.
문제 번호	1	2	3	4	5	6	7
데드라인	1	1	3	3	2	2	6
컵라면 수	6	7	2	1	4	5	1
위와 같은 상황에서 동호가 2, 6, 3, 1, 7, 5, 4 순으로 숙제를 한다면 2, 6, 3, 7번 문제를 시간 내에 풀어 총 15개의 컵라면을 받을 수 있다.
문제는 동호가 받을 수 있는 최대 컵라면 수를 구하는 것이다. 위의 예에서는 15가 최대이다.
문제를 푸는데는 단위 시간 1이 걸리며, 각 문제의 데드라인은 N이하의 자연수이다. 또, 각 문제를 풀 때 받을 수 있는 컵라면 수와 최대로 받을 수 있는
 컵라면 수는 모두 2^31보다 작거나 같은 자연수이다.

입력
첫 줄에 숙제의 개수 N (1 ≤ N ≤ 200,000)이 들어온다. 다음 줄부터 N+1번째 줄까지 i+1번째 줄에 i번째 문제에 대한 데드라인과 풀면 받을 수 있는 컵라면 수가
 공백으로 구분되어 입력된다.

출력
첫 줄에 동호가 받을 수 있는 최대 컵라면 수를 출력한다.
 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;

class comp {
public:
    bool operator()(pii &a, pii &b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int select[200001];// select[i] = ith 데드라인에 제출할 과제의 컵라면 수
priority_queue<pii, vector<pii>, comp> prob{};
priority_queue<int, vector<int>, greater<>> ans_queue{}; // 상위 N개를 저장하는 장소 -> time = t일 때 t개까지만 저장해야 한다.
int main()
{
    FastIO;
    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        prob.emplace(tmp1, tmp2);
    }

    long long ans = 0;

    for (int i = 0; i < N; ++i) {
       ans_queue.push(prob.top().second);
       if(ans_queue.size() > prob.top().first) ans_queue.pop();
       prob.pop();
    }
    while (!ans_queue.empty()) {
        ans += ans_queue.top(); ans_queue.pop();
    }

    cout << ans;



}