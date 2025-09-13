#include <iostream>

/*
    윤년
    https://www.acmicpc.net/problem/2753
*/

int main() {
    int year;
    std::cin >> year;
    if (year%400==0) {
        std::cout << 1 << std::endl;
    }
    else if (year%4==0 && year%100!=0) {
        std::cout << 1 << std::endl;
    }
    else {
        std::cout << 0 << std::endl;
    }
    return 0;
}