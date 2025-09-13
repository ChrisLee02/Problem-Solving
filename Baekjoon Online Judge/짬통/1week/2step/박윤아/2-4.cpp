/*
14681 - 사분면 고르기
https://www.acmicpc.net/problem/14681
*/

#include <iostream>
using namespace std;

int main(){
    int x, y, n;
    cin>>x>>y;

    if(x>0) n=1;
    else n=2;
    if(y<0) n=5-n;

    cout<<n<<endl;
}