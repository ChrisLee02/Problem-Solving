/*
어떤 수가 소수의 N제곱(N ≥ 2) 꼴일 때, 그 수를 거의 소수라고 한다.

두 정수 A와 B가 주어지면, A보다 크거나 같고, B보다 작거나 같은 거의 소수가 몇 개인지 출력한다.

입력
첫째 줄에 왼쪽 범위 A와 오른쪽 범위 B가 공백 한 칸을 사이에 두고 주어진다.
1 ≤ A ≤ B ≤ 10^14
출력
첫째 줄에 총 몇 개가 있는지 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;

vector<long> primes{};
vector<bool> states(10000001, true);

long long safe_mul(long long a, long long b) {
    if(a > LONG_LONG_MAX / b)
    {
        return -1;
    }
    return a*b;
}

int main()
{
    long long A, B;
    cin >> A >> B;
    states[1] = false;

    for (long i = 2; i*i <= 10000000; ++i) {
        if(states[i]) {
            for (long j = i*i; j <= 10000000 ; j+=i) {
                states[j] = false;
            }
        }
    }

    for (long i = 2; i <= 10000000; ++i) {
        if(states[i]) primes.push_back(i);
    }
    long long cnt = 0;
    for (long prime:primes) {
      //  cout << "prime: " << prime << " ";
        for (long long i = safe_mul(prime, prime); i <= B; i = safe_mul(i,prime)) {
            if(i == -1) break;
            if(i<A) continue;
            cnt++;
       //     cout << i << " ";
        }
       // cout << '\n';
    }
    cout << cnt;


}


