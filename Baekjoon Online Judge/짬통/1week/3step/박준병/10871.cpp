#include <iostream>
#include <vector>
using namespace std;
/*
3단계 x보다 작은 수 
https://www.acmicpc.net/problem/10871
*/

int main(){

    int N,X;
    cin >> N >> X;
    std::vector<int> arr(N-1);

    for (int i = 0 ; i<N; i++){
        cin >> arr[i];
    }

    for (int i = 0 ; i<N; i++){
        if(arr[i] < X){
            cout << arr[i] << " ";
        }

    }

    return 0;

}