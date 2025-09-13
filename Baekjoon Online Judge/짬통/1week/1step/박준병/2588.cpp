#include <iostream>

/*
백준 곱셈 문제
https://www.acmicpc.net/problem/2588
*/

int main(){
    int num1, num2;
    std::cin >> num1 >> num2; 

    int num3, num4, num5, result;
    result = num1 * num2; 
    num3 = num2 % 10 ;
    num2 = num2 / 10;
    num4 = num2 % 10;
    num2 = num2 / 10;
    num5 = num2 % 10;

    std::cout << num1 *num3 << std::endl 
              << num1 *num4 << std::endl 
              << num1 *num5 << std::endl
              << result << std::endl;
    return 0; 
}