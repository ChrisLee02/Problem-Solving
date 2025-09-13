/*
언니 엘자와 동생 안나에게는 N개의 눈덩이가 있다. 각 눈덩이 i (1 ≤ i ≤ N)의 지름은 Hi 이다. 하나의 눈사람은 두 개의 눈덩이로 구성되며,
 눈덩이 하나를 아래에 두고 그 눈덩이보다 크지 않은 다른 눈덩이를 쌓아올리는 방식으로 만들 수 있다. 이때, 눈사람의 키는 두 눈덩이 지름의 합과 같다.

엘자와 안나는 눈덩이 N개 중 서로 다른 4개를 골라서 눈사람을 각각 1개씩, 총 2개를 만들려고 한다. 두 자매는 두 눈사람의 키의 차이가 작을수록
두 눈사람의 사이가 좋을 것이라고 믿는다. 우리는 엘자와 안나가 가장 사이좋은 두 눈사람을 만들기 위해서 도와주려고 한다.

주어진 N개의 눈덩이를 이용하여 만들 수 있는 두 눈사람의 키 차이 중 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N (4 ≤ N ≤ 600)이 주어진다.
둘째 줄에는 각 눈덩이 i (1 ≤ i ≤ N)의 지름을 의미하는 정수 Hi (1 ≤ Hi ≤ 10^9)가 공백으로 구분되어 주어진다.

출력
만들 수 있는 두 눈사람의 키 차이 중 최솟값을 나타내는 정수를 출력하라.
 */

#include <bits/stdc++.h>
#define Pair pair<int, int>

using namespace std;

int N;
vector<int> snowball{};

vector<pair<int, Pair>> snowman{};

bool comp_snowman(pair<int, Pair> &a, pair<int, Pair> &b) {
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp; snowball.push_back(tmp);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            snowman.emplace_back(snowball[i] + snowball[j], Pair(i, j));
        }
    }
    std::sort(snowman.begin(), snowman.end(), comp_snowman);
    /*for (int i = 0; i < snowman.size();++i) {
        cout << snowman[i].first << "   ";
    }
    cout<<endl;
    for (int i = 0; i < snowman.size();++i) {
        cout << snowman[i].second.first << " " << snowman[i].second.second << " ";
    }
    cout<<endl;*/
    int ans = 2100000000;
    for (int i = 0; i < snowman.size(); ++i) {
        int j = i+1;
        set<int> indexes{};
        indexes.insert(snowman[i].second.first);
        indexes.insert(snowman[i].second.second);
        /*for(int i: indexes) {
            cout << i << " ";
        }*/
        // cout<<endl;
        //cout << " // " << snowman[i].first <<": ";
        while(j<snowman.size() && (indexes.find(snowman[j].second.first) != indexes.end() || indexes.find(snowman[j].second.second) != indexes.end()) ) {
           // cout << snowman[j].first << " (" << snowman[j].second.first << " " << snowman[j].second.second <<") ";
            j++;
        }
       // cout << endl;
        if(j<snowman.size()) {
            ans = min(ans, snowman[j].first - snowman[i].first);
        }
    }
    cout << ans;




    //정렬하고 나서, 연속하는 네 개를 고르는게 무조건 최적인가?
    //그건 아님,,


}