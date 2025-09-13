// A+B - 5 https://www.acmicpc.net/problem/10952

#include <iostream>
using namespace std;

int main(){
    int A, B;
    cin>>A>>B;
    while(A!=0&&B!=0){
        cout<<A+B<<"\n";
        cin>>A>>B;
    }
}