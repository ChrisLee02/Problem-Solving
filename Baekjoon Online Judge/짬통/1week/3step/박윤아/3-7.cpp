//11021 - A+B - 7 https://www.acmicpc.net/problem/11021

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T, A, B;
    cin>>T;
    for(int i=1; i<T+1; i++){
        cin>>A>>B;
        cout<<"Case #"<<i<<": "<<A+B<<"\n";
    }
}