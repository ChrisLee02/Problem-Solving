//8393 - 합 https://www.acmicpc.net/problem/8393

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, result=0;
    cin>>n;
    for(; n>0; n--){
        result+=n;
    }
    cout<<result;
}