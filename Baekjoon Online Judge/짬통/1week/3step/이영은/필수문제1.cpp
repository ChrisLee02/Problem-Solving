#include <iostream>

/*
    별 찍기 - 2
    https://www.acmicpc.net/problem/2439
*/

int main() {
    int line;
    std::cin >> line;
    for(int i=0;i<line;i++){
        for(int j=1;j<=line;j++){
            if(line-j>i){
                std::cout << " ";
            }
            else{
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}