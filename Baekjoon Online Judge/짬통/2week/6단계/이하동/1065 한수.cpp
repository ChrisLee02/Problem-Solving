/* https://www.acmicpc.net/problem/1065

어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다.
 N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 

입력
첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


bool isHanSu(int n)
{
    int tmp = n;
    string num;
    while(n>0){
        num.push_back(n%10 + '0');
        n/=10;
    }
    reverse(num.begin(),num.end());
    if(num.length() < 3) {
        return true;
    }
    else {
        return num[0] + num[2] == 2*num[1];
    }
}

int main(void)
{
    int n;
    int count = 0;
    cin >> n;
    for(int i = 1; i<=n; i++) {
        if(isHanSu(i)) {
            count++;
        }
    }
    cout << count;
}

