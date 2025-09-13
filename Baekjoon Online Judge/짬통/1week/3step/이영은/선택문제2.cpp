#include <iostream>
#include <cstdio>

/*
    빠른 A+B
    https://www.acmicpc.net/problem/15552
*/

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A, B, N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A >> B;
        cout << A+B << "\n";
    }
    return 0;
}