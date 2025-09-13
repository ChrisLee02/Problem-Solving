/*
Elly는 예상치 못하게 프로그래밍 대회를 준비하는 학생들을 가르칠 위기에 처했다. 대회는 정확히 3명으로 구성된 팀만 참가가 가능하다.
 그러나 그녀가 가르칠 학생들에게는 큰 문제가 있었다. 코딩 실력이 좋으면 팀워크가 떨어지고, 팀워크가 좋을수록 코딩 실력이 떨어진다.
 그리고 출전하고자 하는 대회는 코딩 실력과 팀워크 모두가 중요하다.

Elly는 그녀가 가르칠 수 있는 모든 학생들의 코딩 실력을 알고 있다. 각각의 코딩 실력 Ai는 -10000부터 10000 사이의 정수로 표시되어 있다.
 그녀는 팀워크와 코딩 실력이 모두 적절한 팀을 만들기 위해, 세 팀원의 코딩 실력의 합이 0이 되는 팀을 만들고자 한다. 이러한 조건 하에,
 그녀가 대회에 출전할 수 있는 팀을 얼마나 많이 만들 수 있는지를 계산하여라.

N명의 학생들의 코딩 실력 Ai가 -10000부터 10000사이의 정수로 주어질 때, 합이 0이 되는 3인조를 만들 수 있는 경우의 수를 구하여라.

입력
입력은 표준 입력으로 주어진다.
첫 번째 줄에 학생의 수 N이 입력된다. 두 번째 줄에 N개의 그녀가 가르칠 학생들의 코딩 실력인 Ai가 주어진다.

출력
표준 출력으로 그녀가 고를 수 있는 팀의 수를 하나의 정수로 출력한다.
 */

#include <bits/stdc++.h>

#define Pair pair<int, int>
using namespace std;

//중복을 허용하고, 중복이 있는 놈들을 후처리해주는 방식
//중복을 허용해서 싹 구하면, 서로 다른 3개의 경우 3번이 더해지고
// 서로다른 2개의 조합의 경우 1번만 더해짐.
// 1개를 세 번 더하는건 안들어간다.

// 중복을 허용해서 다 구한다. 서로다른 2개의 조합 (ex. 1 1 2)를 제거한다. 이때 0을 세 번 더하는 경우가 들어갈 수 있으니 예외철
// 2개의 조합을 빼준 후 3으로 나눈다.

/// 강의 풀이는 N^2logN의 풀이를 썼지만,N^2에 나누기 2가 들어가서 충분히 되는듯.


vector<Pair> student_list{};
int x_plus_y_count[40001];


bool comp_student(const Pair &a, const Pair &b) {
    return a.second < b.second;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin>>tmp;
        student_list.emplace_back(i,tmp);
    }

    std::sort(student_list.begin(), student_list.end(), comp_student);

    for (int i = 0; i < N-1; ++i) {
        for (int j = i+1; j < N; ++j) {
            x_plus_y_count[student_list[i].second + student_list[j].second + 20000]++;
        }
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += x_plus_y_count[-1*student_list[i].second + 20000];
    }

    for (int i = 0; i < N; ++i) {
        const Pair target = Pair(0,student_list[i].second * (-2));
        int count = upper_bound(student_list.begin(),student_list.end(), target, comp_student) - lower_bound(student_list.begin(),student_list.end(), target, comp_student);
        if(student_list[i].second == 0) count--;

        ans -= count;
    }

    cout << ans/3;



}