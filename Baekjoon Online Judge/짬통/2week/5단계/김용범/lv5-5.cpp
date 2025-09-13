#include <iostream>

using namespace std;

int main(){
    int n;
    float *list;
    float max = -1;
    float sum = 0;
    cin >> n;
    list = new float[n];
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    for (int i = 0; i < n; i++) {
        if (list[i] > max) {
            max = list[i];
        }
    }
    for (int i = 0; i < n; i++) {
        list[i] = (list[i] * 100) / max;
    }
    for (int i = 0; i < n; i++) {
        sum += list[i];
    }

    float newmean = sum / n;

    cout << newmean << endl;

    delete[] list;

    return 0;


}