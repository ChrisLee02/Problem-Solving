#include <iostream>

/*
알람 시계 문제
https://www.acmicpc.net/problem/2884
*/

int main(){

    int H, M;
    std::cin >> H >> M ;

    if ( M >= 45 && M <= 59) M -= 45;
    else if ( M >= 0 && M < 45){
        if (H == 0)
        {
            H = 23;
            M = M + 60 - 45;
        }
        else
        {
            H -= 1;
            M = M + 60 - 45;
        }
    }
    std::cout << H << " " << M  << std::endl;

}