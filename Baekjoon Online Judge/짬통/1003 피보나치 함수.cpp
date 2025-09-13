#include <iostream>
#include <string>

using namespace std;

void fibonacci(int n, int list[41], int *count0, int *count1) {
    if (n == 0) {
        (*count0)++;
    } else if (n == 1) {
        (*count1)++;
    } else {
        fibonacci(n-1, count0, count1,list);
        fibonacci(n-2, count0, count1,list);
    }
}

int main(void) {
    int N,T;
    int list[41][2];
    cin >> T;
    list[0][0] = 1;
    list[0][1] = 0;
    list[1][0] = 0;
    list[1][1] = 1;
    int count1, count0;
    for(int i = 2; i <=40; i++) {
        list[i][0] = list[i-1][0] + list[i-2][0];
        list[i][1] = list[i-1][1] + list[i-2][1];
    }
    for(int i = 0; i < T; i++) {
        count0 = 0;
        count1 = 0;
        cin >> N;
        cout << list[N][0] << " "<<list[N][1] << '\n';
    }
}
