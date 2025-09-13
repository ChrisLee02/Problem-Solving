#include <iostream>

/*
3단계 별 찍기 - 1 
https://www.acmicpc.net/problem/2438
*/

int main(){

    int n;
    std::cin >> n;
  

    for (int i = 0 ; i < n ; i++){
        
        for (int k = 0; k<i+1; k++) std::cout <<"*";
        std::cout << std::endl;
    }
    return 0;
    
}