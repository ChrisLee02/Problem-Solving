// 더하기 사이클 https://www.acmicpc.net/problem/1110

#include <iostream>
using namespace std;

int main(){
    int N, A, length=1;
    cin>>N;
    A=10*(N%10)+((N/10)+(N%10))%10;
    while(N!=A){
        A=10*(A%10)+((A/10)+(A%10))%10;
        length++;
    }
    cout<<length;
}