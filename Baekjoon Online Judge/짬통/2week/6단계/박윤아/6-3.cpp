// 한수 https://www.acmicpc.net/problem/1065

#include <iostream>
using namespace std;

bool check_hansoo(int n){
    int d=n%10-(n/10)%10;
    n/=10;
    while(n>9){
        if(n%10-(n/10)%10!=d) return 0;
        n/=10;
    }
    return 1;
}
int main(){
    int N, cnt=0;
    cin>>N;
    for(int i=1; i<N+1; i++){
        if(check_hansoo(i)) cnt++;
    }
    cout<<cnt;
}