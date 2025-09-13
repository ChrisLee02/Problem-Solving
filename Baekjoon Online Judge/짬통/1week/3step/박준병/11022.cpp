#include <iostream>
using namespace std;

/*
3단계 A+B- 8 문제
https://www.acmicpc.net/problem/11022

*/

int main(){
    int T,a,b;
    cin >> T;
    for (int i = 0; i< T ; i++){
        cin >> a >> b;
        cout << "Case #" << i+1 << ": " << a << " + " << b << " = " << a+b << endl;
    }
    return 0;
}
