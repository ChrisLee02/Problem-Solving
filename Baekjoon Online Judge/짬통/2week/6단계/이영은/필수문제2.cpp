/*
    셀프넘버
    https://www.acmicpc.net/problem/4673
*/

#include <iostream>

using namespace std;

int main() {
    int lst[10000]={0, };
    for(int i=0;i<10000;i++){
        int j=i+1;
        int n=j+j%10+(j/10)%10+(j/100)%10+(j/1000)%10;
        if(n<=10000) lst[n-1]=1;
    }
    for(int k=0;k<10000;k++){
        if(lst[k]==0){
            cout << k+1 << endl;
        }
    }
    return 0;
}