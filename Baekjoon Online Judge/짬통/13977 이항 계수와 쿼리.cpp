

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
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    unsigned long long N, K;
    int M = 1000000007;
    int T;
    cin >> T;
    unsigned long long *facModM = new unsigned long long[4000001];
    facModM[0] = 1;
    for(int i = 1; i<4000001; i++) { //400만개에 해당하는 팩토리얼 역원은 미리 계산을 해야되는,,? 1.6mb정도
    //1~k까지 전부 다 NPowPModM을 호출하는게 무리인듯
        facModM[i] = (facModM[i-1] * i)%M;
    }
    unsigned long long result;
    for(int i = 0; i<T; i++) {
        result = 1;
        cin >> N >> K;
        result = (result * NPowPmodM(facModM[N],1, M))%M;
    result = ((result%M) * (NPowPmodM(facModM[N-K], M-2, M)))%M;
    result = ((result%M) * (NPowPmodM(facModM[K], M-2, M)))%M;
         cout << result << '\n';

    }
    
    

   
}