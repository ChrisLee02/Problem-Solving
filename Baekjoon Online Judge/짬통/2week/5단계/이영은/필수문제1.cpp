/*
    최소, 최대
    https://www.acmicpc.net/problem/10818
*/
#include <iostream>

using namespace std;

int main() {
    int N, max, min;
    cin >> N;
    for(int i=0;i<N;i++){
        int A;
        cin >> A;
        if(i==0){
            max=A;
            min=A;
        }
        else{
            if(max<A) max=A;
            if(min>A) min=A;
        }
    }
    cout << min << " " << max << endl;
    return 0;
}