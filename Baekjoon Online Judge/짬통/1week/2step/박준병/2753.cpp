#include <iostream>

/*
윤년 문제
https://www.acmicpc.net/problem/2753
*/

int main(){
    int boolean_num, num1 ;
    std::cin >> num1;
    
    if ((num1 % 4 == 0 && num1 % 100 != 0) || (num1 % 400 == 0)){
        boolean_num = 1;
    }
    else boolean_num = 0;
    
    std::cout << boolean_num << std::endl;
    
}