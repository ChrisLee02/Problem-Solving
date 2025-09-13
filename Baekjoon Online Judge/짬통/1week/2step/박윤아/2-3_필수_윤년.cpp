/*
2753 - 윤년
https://www.acmicpc.net/problem/2753
*/

#include <iostream>
using namespace std;

int main(){
    int year, leap=0;
    cin>>year;

    if(year%4==0){
        if(year%400==0) leap=1;
        else if(year%100!=0) leap=1;
    }
    cout<< leap <<endl;
}