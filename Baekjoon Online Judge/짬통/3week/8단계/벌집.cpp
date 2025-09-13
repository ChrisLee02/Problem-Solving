// https://www.acmicpc.net/problem/2292

#include <iostream>
#include <cmath>

using namespace std;


int main(void){
    int N,i = 1;
    int stair = 0;
    cin >> N;
    while(1) {
        if(N==1) break;
        if( i<N && N<=i+6*stair )break;
        i = i+6*stair;
        stair++;
    }
    cout << stair+1;
}   