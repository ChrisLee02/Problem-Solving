/* https://www.acmicpc.net/problem/11444
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 
두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 n번째 피보나치 수를 1,000,000,007으로 나눈 나머지를 출력한다 */

// 0 1
// 1 1 의 N제곱을 해봅시당,,ㅋ


#include <iostream>

using namespace std;

int mod = 1000000007;

long long** MultiplyMatrix(long long **A, long long **B, long long N, long long M, long long K) {
    long long **C = new long long*[N];
    for(int i = 0; i<N;i++) {
        C[i] = new long long[N];
        for(int j = 0; j<N;j++) {
            C[i][j] = 0;
        }
    }

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<K; j++) {
            for(int k = 0; k<M; k++) {
                C[i][j] = (C[i][j]%mod + (A[i][k]%mod)*(B[k][j]%mod)%mod)%mod;
            }
        }
    }
    return C;
}

long long** MatrixPow(long long **A, long long B,int N) {
    if(B==1) return A;
    long long b = B/2;
    long long **tmp = MatrixPow(A, b, N);
    long long **tmp2 = MultiplyMatrix(tmp, tmp, N,N,N);  
    // for(int i = 0; i<N;i++) {
    //     for(int j = 0; j<N;j++) {
    //         cout << 짬통[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for(int i = 0; i<N;i++) {
    //     for(int j = 0; j<N;j++) {
    //         cout << tmp2[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    if(B%2 == 0) {
        return tmp2;  
    } 
    else {
        return MultiplyMatrix(tmp2, A, N, N, N); 
    }
}

int main(void) {
    long long N,M,K,B,n;
    //cin >> N >> B;
    cin >> n;
    N=2;
    long long **A = new long long*[N];
    A[0] = new long long[N]; 
    A[1] = new long long[N];
    A[0][0] = 0;
    A[0][1] = 1;
    A[1][0] = 1;
    A[1][1] = 1;
    
    long long **C = MatrixPow(A, n, N);
    // for(int i = 0; i<N;i++) {
    //     for(int j = 0; j<N;j++) {
    //         cout << C[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << C[1][0];
}
