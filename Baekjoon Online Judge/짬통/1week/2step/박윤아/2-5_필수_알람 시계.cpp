/*
2884 - 알람 시계
https://www.acmicpc.net/problem/2884
*/

#include <iostream>
using namespace std;

int main(){
    int H, M;
    cin>>H>>M;

    H = (60*H+M+1440-45)%1440/60;
    M = (60*H+M+1440-45)%1440%60;
    
    cout<<H<<" "<<M;
}