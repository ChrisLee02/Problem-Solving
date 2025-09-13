#include <iostream>

/*
    알람 시계
    https://www.acmicpc.net/problem/2884
*/

int main() {
    int hour, min;
    std::cin >> hour >> min;
    if(min>=45){
        std::cout << hour << " " << min-45 << std::endl;
    }
    else if(hour!=0){
        std::cout << hour-1 << " " << min+15 << std::endl;
    }
    else{
        std::cout << "23 " << min+15 << std::endl;
    }
    return 0;
}