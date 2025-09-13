/* https://www.acmicpc.net/problem/1021

지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다. 지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.

지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.

첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
큐에 처음에 포함되어 있던 수 N이 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. (이 위치는 가장 처음 큐에서의 위치이다.) 이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다. N은 50보다 작거나 같은 자연수이고, M은 N보다 작거나 같은 자연수이다. 둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다. 위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제의 정답을 출력한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

void first(deque<int> &a)
{
    a.pop_front();
}

void second(deque<int> &a)
{
}

void third(deque<int> &a)
{
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, K, tmp, count1, count2;
    int totCount = 0;
    cin >> N >> M;
    deque<int> nums1;
    vector<int> target;
    int Target;
    for (int i = 1; i <= N; i++)
    {
        nums1.push_back(i); //뒤에서부터 넣어야 먼저 넣은 친구가 앞으로 가겠죠? 이 등신아?
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> tmp;
        target.push_back(tmp);
    }
    //현재 사이즈랑, front값을 알면 직접 순회하지 않아도 타켓의 위치를 알 수 있다.
    for (int i = 0; i < M; i++)
    {
        Target = target[i];
        count1 = 0;
        count2 = 0;
        while (nums1.front() != Target)
        {
            nums1.push_back(nums1.front());
            nums1.pop_front();
            count1++;
        }
        
        count2 = nums1.size() - count1;
       // cout << count1 << " "<< count2 <<endl;
        if (count2 > count1)
        {
            //cout << 1<< " " << count1 << endl;
            totCount += count1;
            nums1.pop_front();
            //continue;
        }
        else
        {
            for (int j = 0; j < count1+count2; j++)
            {
                nums1.push_front(nums1.back());
                nums1.pop_back();
            }
            nums1.pop_front();
            //cout << 2 << " " << count2 << endl;
            totCount += count2;
            //continue;
        }
    }
    cout<<totCount;
}