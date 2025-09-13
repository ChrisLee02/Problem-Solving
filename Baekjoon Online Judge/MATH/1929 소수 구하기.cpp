/*
문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
vector<bool> states(1000001, true);

int main()
{
    int M, N;
    cin >> M >> N;
    states[1] = false;
    for(int i = 2; i*i<=N; i++) {
        if(states[i]) {
            for(int j = i*i; j<=N; j+=i) {
                states[j] = false;
            }
        }
    }

    for(int i = M; i<=N; i++) {
        if(states[i]) cout << i << '\n';
    }

}