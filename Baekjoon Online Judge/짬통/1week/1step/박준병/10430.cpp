#include <iostream>

/*
1단계 - 나머지 문제
https://www.acmicpc.net/problem/10430
*/

int main(){
    int a,b,c;
    std::cin >> a >> b >> c;
    std::cout << (a+b)%c << std::endl 
              << ((a%c)+(b%c))%c <<std::endl
              << (a*b)%c << std::endl 
              << ((a%c)*(b%c))%c ;

    return 0;
}