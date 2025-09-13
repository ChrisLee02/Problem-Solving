//2588 - 곱셈 https://www.acmicpc.net/problem/2588

#include <iostream>
using namespace std;

int main(){
    int num1, num2, temp=1, result=0;
    cin>> num1;
    cin>> num2;

    for(int i=0; i<3; i++){
        cout<< num1*(num2%10) <<endl;
        result += num1*(num2%10)*temp;
        num2 /= 10;
        temp *=10;
    }
    cout<< result <<endl;
}
