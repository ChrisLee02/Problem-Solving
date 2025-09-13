/*
1330 - 두 수 비교하기
https://www.acmicpc.net/problem/1330
*/


#include <iostream>
using namespace std;

int main(){
    int A, B;
    cin>> A >> B;
    
    if(A>B) cout<<">"<<endl;
    else if(A<B) cout<<"<"<<endl;
    else cout<<"=="<<endl;
}