/*
다솜이는 유료 고속도로를 가지고 있다. 다솜이는 현재 고속도로에 휴게소를 N개 가지고 있는데, 휴게소의 위치는 고속도로의 시작으로부터 얼만큼 떨어져 있는지로 주어진다.
 다솜이는 지금 휴게소를 M개 더 세우려고 한다.
다솜이는 이미 휴게소가 있는 곳에 휴게소를 또 세울 수 없고, 고속도로의 끝에도 휴게소를 세울 수 없다. 휴게소는 정수 위치에만 세울 수 있다.

다솜이는 이 고속도로를 이용할 때, 모든 휴게소를 방문한다. 다솜이는 휴게소를 M개 더 지어서 휴게소가 없는 구간의 길이의 최댓값을 최소로 하려고 한다.
 (반드시 M개를 모두 지어야 한다.)

예를 들어, 고속도로의 길이가 1000이고, 현재 휴게소가 {200, 701, 800}에 있고, 휴게소를 1개 더 세우려고 한다고 해보자.
일단, 지금 이 고속도로를 타고 달릴 때, 휴게소가 없는 구간의 최댓값은 200~701구간인 501이다. 하지만, 새로운 휴게소를 451구간에 짓게 되면,
 최대가 251이 되어서 최소가 된다.

입력
첫째 줄에 현재 휴게소의 개수 N, 더 지으려고 하는 휴게소의 개수 M, 고속도로의 길이 L이 주어진다. 둘째 줄에 현재 휴게소의 위치가 공백을 사이에 두고 주어진다.
 N = 0인 경우 둘째 줄은 빈 줄이다.

출력
첫째 줄에 M개의 휴게소를 짓고 난 후에 휴게소가 없는 구간의 최댓값의 최솟값을 출력한다.

제한
0 ≤ N ≤ 50 /// 1 ≤ M ≤ 100 /// 100 ≤ L ≤ 1,000 /// 1 ≤ 휴게소의 위치 ≤ L-1 /// N+M < L /// 모든 휴게소의 위치는 중복되지 않음
입력으로 주어지는 모든 수는 정수
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, L;
vector<int> exist_buildings{};

bool isAble(int x) {
    int cnt_building = 0;
    int building_index = 0;
    int start = 0;
    int end;
    while(building_index < exist_buildings.size()) {
        end = exist_buildings[building_index];
        while(start + x < end) {
            cnt_building++;
            start += x;
        }
        start = end;
        building_index++;
    }
    end = L;
    while(start + x < end) {
        cnt_building++;
        start += x;
    }

    return cnt_building <= M;
}

int param_search() { // 휴게소가 없는 구간의 길이(=x)를 최솟값으로 만들어야 한다.
    // M값이 커지면 x는 작아진다. x를 만들기 위한 M값을 구해서 주어진 M값보다 크거나 같은 경우 x를 더 작게, 휴게소가 부족하면 x를 더 크게.
    int left = 1;
    int right = 1000;
    while(left < right) {
        int mid = (left + right) / 2;
        // cout << mid << endl;
        if(isAble(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> L;
    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp; exist_buildings.push_back(tmp);
    }
    std::sort(exist_buildings.begin(), exist_buildings.end());
    cout << param_search();

}