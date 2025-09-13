/*
    평균
    https://www.acmicpc.net/problem/1546
*/

#include <iostream>

using namespace std;

int main() {
    float N, grade, max=0, sum=0;
    float result;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> grade;
        if(grade>max) max=grade;
        sum=sum+grade;
    }
    result=((sum/max)*100)/N;
    cout << result << endl;
    return 0;
}