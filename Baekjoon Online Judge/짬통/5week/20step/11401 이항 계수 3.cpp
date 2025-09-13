/* https://www.acmicpc.net/problem/11401
자연수 \(N\)과 정수 \(K\)가 주어졌을 때 이항 계수 
\(\binom{N}{K}\)를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 \(N\)과 \(K\)가 주어진다. (1 ≤ \(N\) ≤ 4,000,000, 0 ≤ \(K\) ≤ \(N\))

출력
 
\(\binom{N}{K}\)를 1,000,000,007로 나눈 나머지를 출력한다. */

#include <iostream>
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


int main(void) 
{
    unsigned long long N, K;
    int M = 1000000007;
    cin >> N >> K;
    unsigned long long *facModM = new unsigned long long[N+1];
    facModM[0] = 1;
    for(int i = 1; i<=N; i++) { //400만개에 해당하는 팩토리얼 역원은 미리 계산을 해야되는,,? 1.6mb정도
    //1~k까지 전부 다 NPowPModM을 호출하는게 무리인듯
        facModM[i] = (facModM[i-1] * i)%M;
    }
    unsigned long long result = 1;
    
    result = (result * NPowPmodM(facModM[N],1, M))%M;
    result = ((result%M) * (NPowPmodM(facModM[N-K], M-2, M)))%M;
    result = ((result%M) * (NPowPmodM(facModM[K], M-2, M)))%M;
    
    cout << result;
}