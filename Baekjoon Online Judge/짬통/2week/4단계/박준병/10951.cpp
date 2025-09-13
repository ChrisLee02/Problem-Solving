/*
4단계 a+b - 4  eof 활용
https://www.acmicpc.net/problem/10951
*/

#include <iostream>
using namespace std;
int main(){

    int a, b;
    
    while(1){
        cin >> a >> b;
        if(cin.eof()) break;
        cout << a+b << endl;
        
    }

    return 0;
}