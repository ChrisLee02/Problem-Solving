#include <iostream>


/*
3단계 별찍기 - 2 문제
https://www.acmicpc.net/problem/2439
*/

int main(){

    int n;
    std::cin >> n;
  

    for (int i = 0 ; i < n ; i++){
        for (int j = n-i-1; j>0; j--) std::cout << " ";
        for (int k = 0; k<i+1; k++) std::cout <<"*";
        std::cout << std::endl;
    }
    return 0;
    
}