// 평균 https://www.acmicpc.net/problem/1546

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M=0;
    long double sum=0.000000;
    cin>>N;
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    for(int i=0; i<N; i++){
        if(arr[i]>M) M=arr[i];
    }
    for(int i=0; i<N; i++){
        sum+=(long double)arr[i]*100/M;
    }
    cout<<(long double)sum/N;
}
