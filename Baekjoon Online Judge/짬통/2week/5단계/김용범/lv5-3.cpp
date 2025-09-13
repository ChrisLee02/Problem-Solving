#include <iostream>
#include <cmath>


using namespace std;

int main(){
    int arr[10] = {0,0,0,0,0,0,0,0,0,0};
    int a,b,c;
    cin >> a >> b >> c;
    int ex = a * b * c;
    while(ex) {
        arr[ex % 10]++;
        ex = ex / 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }
    
    return 0;
}