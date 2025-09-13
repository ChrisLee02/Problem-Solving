/*
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
 */


#include <bits/stdc++.h>

int howUsed[10001];
int ableTime[10001];
bool isUsed[10];
int seq[10];
int Nums[10];
using namespace std;

void NandM(int size, int N, int M) {
    if (size == M) {
        for (int i = 0; i < M; i++) cout << seq[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (howUsed[Nums[i]] < ableTime[Nums[i]]) {
            seq[size] = Nums[i];
            howUsed[Nums[i]]++;
            NandM(size + 1, N, M);
            howUsed[Nums[i]]--;
        }
    }

}

int main() {
    int N, M, tmp;
    cin >> N >> M;
    set<int> tmp2;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        tmp2.insert(tmp);
        ableTime[tmp]++;
    }
    auto p = Nums;
    for (int i: tmp2) {
        *p = i;
        p++;
    }
    N = tmp2.size();
    sort(Nums, Nums + N);
    NandM(0, N, M);
}