#include <iostream>

/*
    사분면 고르기
    https://www.acmicpc.net/problem/14681
*/

int main() {
    int x, y;
    std::cin >> x >> y;
    if(x*y>0){
        if(x>0){
            std::cout << "1" << std::endl;
        }
        else{
            std::cout << "3" << std::endl;
        }
    }
    else{
        if(x>0){
            std::cout << "4" << std::endl;
        }
        else{
            std::cout << "2" << std::endl;
        }
    }
    return 0;
}