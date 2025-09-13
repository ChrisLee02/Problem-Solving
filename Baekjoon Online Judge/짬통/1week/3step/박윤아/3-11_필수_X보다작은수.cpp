//10871 - X보다 작은 수 https://www.acmicpc.net/problem/10871

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, X, a;
    cin>>N>>X;
    for(int i=0; i<N; i++){
        cin>>a;
        if(a<X) cout<<a<<" ";
    }
}