/*
    나머지
    https://www.acmicpc.net/problem/3052
*/

#include <iostream>

using namespace std;

int main(){
    int A, r, count=0;
    int rest[42]={0,};
    for(int i=0;i<10;i++){
        cin >> A;
        r=A%42;
        if(rest[r]==0){
            rest[r]=1;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}