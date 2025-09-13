/* https://www.acmicpc.net/problem/11401
자연수 \(N\)과 정수 \(K\)가 주어졌을 때 이항 계수 
\(\binom{N}{K}\)를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 \(N\)과 \(K\)가 주어진다. (1 ≤ \(N\) ≤ 4,000,000, 0 ≤ \(K\) ≤ \(N\))

출력
 
\(\binom{N}{K}\)를 1,000,000,007로 나눈 나머지를 출력한다. */

#include <iostream>
#include <vector>
#include <tuple>



using namespace std;

//NCR을 진짜 반복문/재귀로 계산해나가는 것.
//이때 분모를 계산할 때는, 모듈러 상의 역원을 곱해주어야 함..
//페르마의 소정리 - a^p-1 = 1 mod p where a and p is coprime
//즉, a의 역원은 a^p-2이고 이를 분할정복으로 해결해주면 끗.

//또는, 

// tuple<int, int, int> expanded_Euclidean(int a, int b) {

// }

unsigned long long NPowPmodM(unsigned long long N, unsigned long long P, unsigned long long M) {
    unsigned long long p = P/2;
    if(P==0) return 1;
    if(P==1) return N%M;
    unsigned long long tmp = NPowPmodM(N, p, M) % M;
    int tmp2 = 1;
    if(P%2 == 0) {
        return (tmp%M * tmp%M)%M;
    }
    else {
        return ((N%M)*(tmp%M * tmp%M)%M)%M ;
    }
}

// tuple<long long, long long, long long>
long long expanded_Euclidean(long long a, long long b) {
    vector<long long> r;
    vector<long long> s;
    vector<long long> t;
    long long q;
    r.push_back(a);
    r.push_back(b);
    s.push_back(1);
    s.push_back(0);
    t.push_back(0);
    t.push_back(1);
    while(r.back()!=0) {
        q = r[r.size()-2] / r[r.size()-1];
        s.push_back( s[s.size()-2] - q*s[s.size()-1] );
        t.push_back(  t[t.size()-2] - q*t[t.size()-1] );
        r.push_back(r[r.size()-2] % r[r.size()-1]);
    }
    if(r[r.size()-2] == 1) {
        return t[t.size()-2];
    }
    else {
        return -1;
    }
}


int main(void) 
{
    unsigned long long N, A, tmp;
    cin >> N >> A;
    cout << N-A << " ";
    tmp = expanded_Euclidean(N, A);
    if(tmp==-1) cout << -1;
    else cout << (tmp+N)%N;
}