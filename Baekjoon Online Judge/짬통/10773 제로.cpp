#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, K;
    int sum =0;
    int tmp;
    cin >> N;
    stack<int> money;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        if(tmp == 0) money.pop();
        else money.push(tmp);
    }
    while(!money.empty()) {
        sum = sum + money.top();
        money.pop();
    }
    cout << sum;
}
