/*비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다. */

#include <bits/stdc++.h>


using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, tmp;
    priority_queue<int, vector<int>, greater<> > list = priority_queue<int, vector<int>, greater<> >();
    // make_heap을 내부에서 사용함, 그래서 greater면 큰게 뒤로 감. 여기선 top을 쓰니까 greater를 쓰면 minheap이 됨.
    cin >> N;
    set<int> S = set<int>();
    set<int> ALL = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for(int i = 0; i<N; i++) {
        string command;
        int n;
        cin >> command;
        if(command == "add") {
            cin >> n;
            S.insert(n);
        }
        if(command == "remove") {
            cin >> n;
            S.erase(n);
        }
        if(command == "check") {
            cin >> n;
            cout << ((S.find(n) == S.end()) ? 0 : 1 ) << '\n';
        }
        if(command == "toggle") {
            cin >> n;
            if(S.find(n) == S.end()) {
                S.insert(n);
            }
            else {
                S.erase(n);
            }
        }
        if(command == "all") {
            S = ALL;
        }
        if(command == "empty") {
            S = set<int>();
        }

    }

}