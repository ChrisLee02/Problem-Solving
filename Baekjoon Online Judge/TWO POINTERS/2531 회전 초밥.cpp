/*
https://www.acmicpc.net/problem/2531
첫 번째 줄에는 회전 초밥 벨트에 놓인 접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c가 각각 하나의 빈 칸을 사이에 두고 주어진다.
 단, 2 ≤ N ≤ 30,000, 2 ≤ d ≤ 3,000, 2 ≤ k ≤ 3,000 (k ≤ N), 1 ≤ c ≤ d이다.
 두 번째 줄부터 N개의 줄에는 벨트의 한 위치부터 시작하여 회전 방향을 따라갈 때 초밥의 종류를 나타내는 1 이상 d 이하의 정수가 각 줄마다 하나씩 주어진다.

출력
주어진 회전 초밥 벨트에서 먹을 수 있는 초밥의 가짓수의 최댓값을 하나의 정수로 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;
int N, d, k, c;

vector<int> sushi{};
int sushi_to_index[3001]; // 가장 최근에 추가된 것의 인덱스

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> d >> k >> c;
    // 접시, 초밥종류, 연속 접시 수, 쿠폰번호
    // 종류 수의 최댓값을 구해야 함.
    // 입력으로는 1~d까지가 들어온다.
    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp; sushi.push_back(tmp);
    }
    for (int i = 1; i <= d; ++i) {
        sushi_to_index[i] = -1;
    }

    int count = 0;
    int ans = 0;
    for (int l = 0; l < k; ++l) { // 초깃값 설정
        if(sushi_to_index[sushi[l]] == -1) {
            count++;
        }
        sushi_to_index[sushi[l]] = l;
    }

    if(sushi_to_index[c] == -1) {
        ans = max(count + 1, ans);
    } else {
        ans = max(count, ans);
    }

    int i = 0;
    int j;
    while(i != N) {
        if(sushi_to_index[sushi[i]] == i) {
            sushi_to_index[sushi[i]] = -1;
            count--;
        }
        i++;
        j = (i + k - 1)%N;

        if(sushi_to_index[sushi[j]] == -1 ) {
            count++;
        }
        sushi_to_index[sushi[j]] = j;

        if(sushi_to_index[c] == -1) {
            ans = max(count + 1, ans);
        } else {
            ans = max(count, ans);
        }

    }

    cout << ans;


}