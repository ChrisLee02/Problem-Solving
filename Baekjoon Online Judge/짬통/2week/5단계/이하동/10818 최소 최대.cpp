/* https://www.acmicpc.net/problem/10818

N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.

출력
첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다. */
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int a, N;
    int max, min;
    vector<int> vec;
    cin >> N;
    for(vector<int>::size_type i=0; i<N; i++) {
        cin >> a;
        vec.push_back(a);
    }
    max = vec[0];
    min = vec[0];
    for(vector<int>::size_type i=0; i<N; i++) {
        if(max < vec[i]) max = vec[i];
        if(min > vec[i]) min = vec[i];
    }
    cout << min << " " << max;

}