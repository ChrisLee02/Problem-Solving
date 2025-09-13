#include <iostream>

int yesorno(int n) {
    if (n < 100) {
        return 1;
    }
    int n1,n2,n3;
    n3 = n / 100;
    n2 = (n % 100) / 10;
    n1 = n % 10;
    if (2 * n2 == n3 + n1) {
        return 1;
    }
    
    else return 0;


}


int main(){
    int count = 0;
    int n;
    std::cin >> n;
    for (int i = 1; i < n + 1; i++) {
        if (yesorno(i)) {
            count++;
        }
    }

    std::cout << count << std::endl;
}