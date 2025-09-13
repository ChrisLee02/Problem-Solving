//1008 - A/B https://www.acmicpc.net/problem/1008

#include <iostream>
using namespace std;

int main(){
    int num1, num2;
    cin >> num1 >> num2;
    cout.precision(16);
    cout << (long double)num1/num2 <<endl;
}