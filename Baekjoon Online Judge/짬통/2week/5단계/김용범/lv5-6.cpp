#include <iostream>

using namespace std;

int main(){
    int n;
    char arr[80];
    for (int i = 0; i < 80; i++){
        arr[i] = '\0';
    }
    cin >> n;
    for (int i = 0; i < n; i++){
        int score = 0;
        int j = 0;
        int tempscore = 0;
        cin >> arr;
        while(arr[j]) {
            if (arr[j] == 'O'){
                tempscore++;
                score += tempscore;
            }
            else{
                tempscore = 0;
            }
            j++;
        }
        cout << score << endl;
    } 
}