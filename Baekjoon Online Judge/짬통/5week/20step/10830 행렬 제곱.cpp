/* https://www.acmicpc.net/problem/10830
크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성하시오. 수가 매우 커질 수 있으니, 
A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.

입력
첫째 줄에 행렬의 크기 N과 B가 주어진다. (2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)

둘째 줄부터 N개의 줄에 행렬의 각 원소가 주어진다. 행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄부터 N개의 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다. */

#include <iostream>

using namespace std;

int mod = 1000;

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
    long long N,M,K,B;
    cin >> N >> B;
    long long **A = new long long*[N];
    for(int i = 0; i<N;i++) {
        A[i] = new long long[N];
        for(int j = 0; j<N;j++) {
            cin >> K;
            A[i][j] = K%1000;
        }
    }
    
    long long **C = MatrixPow(A, B, N);
    for(int i = 0; i<N;i++) {
        for(int j = 0; j<N;j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
}