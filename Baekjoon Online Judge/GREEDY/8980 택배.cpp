/*
입력
입력의 첫 줄은 마을 수 N과 트럭의 용량 C가 빈칸을 사이에 두고 주어진다. N은 2이상 2,000이하 정수이고, C는 1이상 10,000이하 정수이다.
 다음 줄에, 보내는 박스 정보의 개수 M이 주어진다. M은 1이상 10,000이하 정수이다. 다음 M개의 각 줄에 박스를 보내는 마을번호, 박스를 받는 마을번호,
 보내는 박스 개수(1이상 10,000이하 정수)를 나타내는 양의 정수가 빈칸을 사이에 두고 주어진다. 박스를 받는 마을번호는 보내는 마을번호보다 크다.

출력
트럭 한 대로 배송할 수 있는 최대 박스 수를 한 줄에 출력한다.
 */

#include <bits/stdc++.h>
#define Pair pair<int,int>
#define Town first
#define Box second
#define Origin first
#define Destination second

using namespace std;
int N, C, M;
int load[2003]; //load[i] = i번쨰 마을에 짐을 내려놓은 뒤 트럭에 있는 짐의 크기.
int sum[2003]; // sum[i] = i번째 마을에 배송한 짐의 크기
bool compare_tuple(pair<Pair, int> &a, pair<Pair, int> &b) {
    if(a.Town.Destination == b.Town.Destination) {
        return a.Town.Origin > b.Town.Origin;
    }
    else {
        return a.Town.Destination < b.Town.Destination;
    }
}

void add_with_max(int &target, int &add_value) {
    target = target + add_value;
    if(target > C) {
        target = C;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> C >> M;
    vector<pair<Pair, int>> infos;

    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        infos.emplace_back(Pair(tmp1,tmp2), tmp3);
    }
    std::sort(infos.begin(), infos.end(), compare_tuple);



    for (int i = 0; i < M; ++i) {
        pair<Pair, int> info = infos[i];
        int max_load = 0;
        for (int j = info.Town.Origin; j < info.Town.Destination; ++j) {
            max_load = max(max_load, load[j]);
        }
        int carried_load = min(info.Box, C - max_load);
        //cout << info.Town.Origin << info.Town.Destination << info.Box <<" " <<carried_load<< endl;
        for (int j = info.Town.Origin; j < info.Town.Destination; ++j) {
            load[j] += carried_load;
          //  cout << j <<": " << load[j] << endl;
        }
        sum[info.Town.Destination] += carried_load;

    }




    int ans = 0;
    for (int i = 1; i <= N; ++i) {
//        cout << sum[i] << " ";
        ans = ans + sum[i];
    }
 //   cout << endl;
    cout << ans;

}
