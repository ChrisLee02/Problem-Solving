#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int num;
    int *list;
    for (int i = 0; i < n; i++){
        int count = 0;
        float sum = 0;
        float percent = 0;
        cin >> num;
        list = new int[num];
        for (int j = 0; j < num; j++) {
            cin >> list[j];
            sum += list[j];
        }
        sum = sum / num;
        for (int j = 0; j < num; j++) {
            if (list[j] > sum) {
                count++;
            }
        }
        
        float num1 = num;
        percent = count * 100  / num1;
        cout << fixed;
        cout.precision(3);
        cout << percent << "%" << endl; 
    }

    return 0;
}