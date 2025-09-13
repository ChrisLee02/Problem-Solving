/*
백준이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다. 백준이가 정수를 하나씩 외칠때마다 동생은 지금까지 백준이가 말한 수 중에서 중간값을 말해야 한다.
 만약, 그동안 백준이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.
예를 들어 백준이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면, 동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다.
 백준이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 백준이가 외치는 정수의 개수 N이 주어진다. N은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수이다.
 그 다음 N줄에 걸쳐서 백준이가 외치는 정수가 차례대로 주어진다. 정수는 -10,000보다 크거나 같고, 10,000보다 작거나 같다.

출력
한 줄에 하나씩 N줄에 걸쳐 백준이의 동생이 말해야 하는 수를 순서대로 출력한다.
 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()


// vec을 하나 만들고, 우선순위 큐를 이용해서 set의 사이즈를 3~4로 유지하면 될 듯 -> NOPE

// N번째 큰 수를 얻는 방법을 이용하면 될 듯. 우선순위 큐 두 개를 잘 어떻게 하면 중간값을 O(1)에 얻을 수 있겟다.
// 두 개 까지도 필요없다. 그냥 최대 힙을 이용해서 최대 힙의 사이즈를 유동적으로 바꿔가면 된다..? 는 안될듯. 그러면 값이 유실될 수 있음.
// 1. 최대 힙의 사이즈는 (int)(N+1)/2 로 유지한다.
// 2. 삽입이 끝난 후, 최대 힙의 top  <= 최소 힙의 top을 유지한다.
// 그 후 최대 힙의 top을 출력한다.
using namespace std;
priority_queue<int> max_heap{};
priority_queue<int, vector<int>, greater<>> min_heap{};

int main()
{
    FastIO;
    int N; cin >> N;


    for (int i = 1; i <= N; ++i) {
        int tmp; cin >> tmp;
        if( (int)(i + 1)/2 > max_heap.size() ) {
            max_heap.push(tmp);
        }
        else {
            min_heap.push(tmp);
        }

        if(!min_heap.empty() && min_heap.top() < max_heap.top() ) {
            int min_tmp = min_heap.top(); min_heap.pop();
            int max_tmp = max_heap.top(); max_heap.pop();
            min_heap.push(max_tmp);
            max_heap.push(min_tmp);
        }

        cout << max_heap.top() << endl;
    }

}