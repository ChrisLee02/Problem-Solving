/*
10818번 최소, 최대
https://www.acmicpc.net/problem/10818
*/

// 노가다로 최대, 최소 구하는 함수해보자.
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int N,x;
    vector<int> v;
    cin >> N;
    
    for (int i = 0; i<N; i++){
        cin >> x;
        v.push_back(x);
    }

    int max = v[0];
    int min  = v[0];

    for (int i = 1 ; i < N ; i ++){
        if(v[i] > max ) max = v[i];
        if(v[i] < min ) min = v[i];
    }

    cout << min << " " << max << endl;
    return 0;
}