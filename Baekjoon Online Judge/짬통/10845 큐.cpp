#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,M, tmp;
    string order;
    cin >> N;
    queue<int> nums;
    for(int i = 0; i < N; i++) {
        cin >> order;
        if(order == "push") {
            cin >> tmp;
            nums.push(tmp);
        }
        if(order == "pop") {
            if(nums.empty()) cout << -1 << '\n';
            else {
                cout << nums.front()<<'\n';
                nums.pop();
            }
        }
        if(order == "size") {
            cout << nums.size() << '\n';
        }
        if(order == "empty") {
            cout << nums.empty() << '\n';
        }
        if(order == "front") {
            if(nums.empty()) cout << -1 << '\n';
            else {
                cout << nums.front()<<'\n';
            }
        }
        if(order == "back") {
            if(nums.empty()) cout << -1 << '\n';
            else {
                cout << nums.back()<<'\n';
            }
        }
    }
    
}