/*

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
        if (Nums[i] >= seq[size-1]) {
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