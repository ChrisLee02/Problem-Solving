/*
4단계 더하기 사이클
https://www.acmicpc.net/problem/1110
*/

#include <iostream>
using namespace std;


int main(){

    int first, tmp ;
    int cnt = 0;
    cin >> first;
    tmp = first;
    while(1){
        int b = tmp/10 + tmp %10;
        int c = (tmp%10) * 10 + b % 10;
       
        if(first == c){
            cnt++;
            break;
        }
        else{ 
            cnt ++;
            tmp = c;
            int c{}; // zero initialization
        }
    }
    cout << cnt << endl;
}

