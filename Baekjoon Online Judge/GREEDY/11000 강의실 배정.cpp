/*
수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다.
김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다.
참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다. (즉, Ti ≤ Sj 일 경우 i 수업과 j 수업은 같이 들을 수 있다.)
수강신청 대충한 게 찔리면, 선생님을 도와드리자!

입력
첫 번째 줄에 N이 주어진다. (1 ≤ N ≤ 200,000)

이후 N개의 줄에 Si, Ti가 주어진다. (0 ≤ Si < Ti ≤ 109)

출력
강의실의 개수를 출력하라.
 */
#include <bits/stdc++.h>

#define lecture pair<int, int>
#define S first
#define T second


using namespace std;

bool compare(lecture &a, lecture &b) {
    return a.S < b.S; // 빨리 시작하는 놈이 앞으로, 시작 시간 같으면 어차피 다 다른 방 쓸거라 순서 의미없음.
}

//int rooms[200001];
// 시작 시간 기준으로 오름차순 정렬 후, 끝나는 시간을 priority queue에 집어넣는다. 어차피 각 방들의 끝나는 시간들 중 최솟값보다 작으면 새 방을 파야함.
// 만약 최솟값보다 크면 그 최솟값이랑 연결하는게 최적임.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<lecture > lectures{};
    priority_queue<int, vector<int>, greater<>> rooms_end_time{};

    for (int i = 0; i < N; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        lectures.emplace_back(tmp1, tmp2);
    }

    sort(lectures.begin(), lectures.end(), compare);

    rooms_end_time.push(lectures[0].T);

    for (int i = 1; i < N; ++i) {
        if (rooms_end_time.top() <= lectures[i].S) {
            rooms_end_time.pop();
        }
        rooms_end_time.push(lectures[i].T);
    }


    //모든 강의를 포함해야 하니까, 일찍 시작하는 애를 빨리 집어넣는게 이득이다.


    cout << rooms_end_time.size();

}
