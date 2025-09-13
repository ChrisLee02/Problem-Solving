/*
https://www.acmicpc.net/problem/22862
 */

#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> seq{};
vector<int> dist_between_even{};

bool isEven(int i) {return i%2 == 0;}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp;
        seq.push_back(tmp);
    }

    int even_index = std::find_if(seq.begin(), seq.end(), isEven) - seq.begin();
    if(even_index == N) { // 짝수 0개인 케이스 예외처리
        cout << 0;
        return 0;
    }

    auto p = std::find_if(seq.begin(), seq.end(), isEven);
    auto next_p = std::find_if(p + 1, seq.end(), isEven);
    while(next_p != seq.end()) {
        dist_between_even.push_back(next_p - p - 1);
        p = next_p;
        next_p = find_if(p + 1, seq.end(), isEven);
    }

    //최대 K번 삭제 후 만들 수 있는 가장 긴 연속하는 짝수 부분수열의 길이를 구해야 한다.
    //짝수들에 번호를 붙여서 1번, 2번, ... , k번 짝수까지 있다고 해보자.
    //그러면 k-1개의 구간에 대해 거리를 정의할 수 있을 것.
    //거리에 대한 배열을 다시 만들어서 이 배열에 대한 부분합 문제로 환원한다.
    //합이 K를 넘지않는 연속합 중 가장 긴 경우를 출력하면 된다.

    if(dist_between_even.empty()) {  // 짝수 1개인 케이스 예외처리
        cout << 1;
        return 0;
    }
    int ans = 1;
    int i = 0;
    int j = 0;
    int sum = dist_between_even[i];
    int count = 1;

    while(j < dist_between_even.size()) {
        if(sum <= K) {
            ans = max(ans, count);
            j++;
            count++;
            sum = sum + dist_between_even[j];
        }

        else {
            sum = sum - dist_between_even[i];
            i++;
            count--;
        }

    }

    cout << ans + 1;






}