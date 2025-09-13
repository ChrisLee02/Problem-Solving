#include <iostream>

/*
    곱셈
    https://www.acmicpc.net/problem/2588
*/

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << a*(b%10) << std::endl
              << a*((b%100)/10) << std::endl
              << a*(b/100) << std::endl
              << a*b << std::endl;
    return 0;
}