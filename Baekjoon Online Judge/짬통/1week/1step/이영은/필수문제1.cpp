#include <iostream>

/*
    사칙연산
    https://www.acmicpc.net/problem/10869
*/

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << a+b << std::endl
              << a-b << std::endl
              << a*b << std::endl
              << a/b << std::endl
              << a%b << std::endl;
    return 0;
}