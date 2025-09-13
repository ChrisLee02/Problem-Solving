/*
4단계 a+b - 5 
https://www.acmicpc.net/problem/10952
*/

#include <iostream>
using namespace std;
int main(){

    int a, b;
    int status = 1;
    while(status){
        cin >> a >> b;
        if (a==0 && b==0) break;
        cout << a+b << endl;
        
    }

    return 0;
}