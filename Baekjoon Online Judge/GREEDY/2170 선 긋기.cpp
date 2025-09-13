/*
매우 큰 도화지에 자를 대고 선을 그으려고 한다. 선을 그을 때에는 자의 한 점에서 다른 한 점까지 긋게 된다.
 선을 그을 때에는 이미 선이 있는 위치에 겹쳐서 그릴 수도 있는데, 여러 번 그은 곳과 한 번 그은 곳의 차이를 구별할 수 없다고 하자.

이와 같은 식으로 선을 그었을 때, 그려진 선(들)의 총 길이를 구하는 프로그램을 작성하시오. 선이 여러 번 그려진 곳은 한 번씩만 계산한다.

입력
첫째 줄에 선을 그은 횟수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 다음 N개의 줄에는 선을 그을 때 선택한 두 점의 위치
 x, y (-1,000,000,000 ≤ x < y ≤ 1,000,000,000)가 주어진다.

출력
첫째 줄에 그은 선의 총 길이를 출력한다.
 */

#include <bits/stdc++.h>
#define Pair pair<int,int>

using namespace std;
// 일단 정렬을 때린 후에, 구간을 합치는 논리를 적용하면 될 것 같아.
// x를 기준으로 오름차순 정렬을 한 뒤에 생각해보자.
// 만약 이어붙이는데 실패하면, 그 뒤에 있는 애들도 시작점이 그 이상이므로 새롭게 줄을 그어주면 됨.
// 그리고 이어붙이는 것을 판단하는 방법은 y를 업뎃하는 방식으로 진행되겠네.

bool compare(Pair &a, Pair &b) {
    return a.first < b.first;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<Pair> lines{};
    for (int i = 0; i < N; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        lines.emplace_back(tmp1,tmp2);
    }
    int sum = 0;
    std::sort(lines.begin(), lines.end(), compare);
    int x = lines[0].first;
    int y = lines[0].second;
    for (int i = 1; i < N; ++i) {
        if(lines[i].first <= y) {
            y = max(y, lines[i].second);
        }
        else {
            sum = sum + (y-x);
            x = lines[i].first;
            y = lines[i].second;
        }
    }
    cout << sum + y-x;
}
