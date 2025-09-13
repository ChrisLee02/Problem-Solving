/* https://www.acmicpc.net/problem/2740
N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 두 행렬을 곱하는 프로그램을 작성하시오.

입력
첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다. 그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다. 이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다. N과 M, 그리고 K는 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.

출력
첫째 줄부터 N개의 줄에 행렬 A와 B를 곱한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다. */

#include <iostream>

using namespace std;

void MultiplyMatrix(int **A, int **B, int **C, int N, int M, int K) {
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<K; j++) {
            for(int k = 0; k<M; k++) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

int main(void) {
    int N,M,K;
    cin >> N >> M;
    int **A = new int*[N];
    int **B = new int*[M];
    for(int i = 0; i<N;i++) {
        A[i] = new int[M];
        for(int j = 0; j<M;j++) {
            cin >> A[i][j];
        }
    }
    cin >> M >> K;
    int **C = new int*[N];
    for(int i = 0; i<N;i++) {
        C[i] = new int[K];
        for(int j = 0; j<K;j++) {
            C[i][j] = 0;
        }
    }
    
    for(int i = 0; i<M;i++) {
        B[i] = new int[K];
        for(int j = 0; j<K;j++) {
            cin >> B[i][j];
        }
    }
    MultiplyMatrix(A,B,C,N,M,K);
    for(int i = 0; i<N;i++) {
        for(int j = 0; j<K;j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

}