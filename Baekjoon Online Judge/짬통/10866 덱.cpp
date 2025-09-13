#include <iostream>
#include <string>
#include <vector>
#include <deque>
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
    deque<int> nums;
    for(int i = 0; i < N; i++) {
        cin >> order;
        if(order == "push_front") {
            cin >> tmp;
            nums.push_front(tmp);
        }
        if(order == "push_back") {
            cin >> tmp;
            nums.push_back(tmp);
        }
        if(order == "pop_back") {
            if(nums.empty()) cout << -1 << '\n';
            else {
                cout << nums.back()<<'\n';
                nums.pop_back();
            }
        }
        if(order == "pop_front") {
            if(nums.empty()) cout << -1 << '\n';
            else {
                cout << nums.front()<<'\n';
                nums.pop_front();
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