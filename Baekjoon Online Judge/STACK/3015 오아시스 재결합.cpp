/*
오아시스의 재결합 공연에 N명이 한 줄로 서서 기다리고 있다.

이 역사적인 순간을 맞이하기 위해 줄에서서 기다리고 있던 백준이는 갑자기 자기가 볼 수 있는 사람의 수가 궁금해 졌다.

두 사람 A와 B가 서로 볼 수 있으려면, 두 사람 사이에 A 또는 B보다 키가 큰 사람이 없어야 한다.

줄에 서있는 사람의 키가 주어졌을 때, 서로 볼 수 있는 쌍의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 줄에서 기다리고 있는 사람의 수 N이 주어진다. (1 ≤ N ≤ 500,000)

둘째 줄부터 N개의 줄에는 각 사람의 키가 나노미터 단위로 주어진다. 모든 사람의 키는 2^31 나노미터 보다 작다.

사람들이 서 있는 순서대로 입력이 주어진다.

출력
서로 볼 수 있는 쌍의 수를 출력한다.
 */

// 내 앞에 키큰사람이 서는 순간 나는 존재의의를 잃어버림. 그때부터 난 없어도 답에 영향을 주지 않음.
// 다 저장해서 더한 뒤 2로 나눠주면 답이 됨.
// 가로막히는 순간이 포착되면 가로막힌 놈들을 싹 다 스택에서 빼줄거야.
// 씨@@@발 입력 범위도 생각해서 자료형 long long으로 맞춰줄 것
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long *Case = new long long[N + 1];
    fill_n(Case, N + 1, 0);
    long long tmp;
    std::stack<pair<long long , int>> stack{}; // 높이, 중복횟수

    for (int i = 1; i <= N; i++) { //
        cin >> tmp;
        if (stack.empty()) {
            stack.push(pair<long long , int>(tmp, 1));

        } else {
            int count = 0;
            int sequence = 1;

            while (!stack.empty() && stack.top().first <= tmp) {
                if(stack.top().first == tmp) {
                    sequence = sequence + stack.top().second;
                }
                count = count + stack.top().second; // 여기를 단순히 +1이 아니라 겹치는 개수를 따져줘야하겠다.
                stack.pop();
            }
            if (stack.empty()) {
                Case[i] = count;

            } else {
                Case[i] = count + 1;
            }
            stack.push(pair<long long, int>(tmp, sequence));
        }
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        //cout << Case[i] << " ";
        ans = ans + Case[i];
    }
    //cout << endl << ans;
    cout << ans;
}