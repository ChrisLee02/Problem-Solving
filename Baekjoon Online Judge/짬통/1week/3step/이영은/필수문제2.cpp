#include <iostream>

/*
    X보다 작은 수
    https://www.acmicpc.net/problem/10871
*/

int main() {
    int N, X, a;
    std::cin >> N >> X;
    for(int i=0;i<N;i++){
        std::cin >> a;
        if(a<X){
            std::cout << a << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}