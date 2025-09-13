/* https://www.acmicpc.net/problem/2565

두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다. 합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.

예를 들어, < 그림 1 >과 같이 전깃줄이 연결되어 있는 경우 A의 1번 위치와 B의 8번 위치를 잇는 전깃줄, A의 3번 위치와 B의 9번 위치를 잇는 전깃줄, A의 4번 위치와 B의 1번 위치를 잇는 전깃줄을 없애면 남아있는 모든 전깃줄이 서로 교차하지 않게 된다.

전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다. 전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때, 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 전봇대 사이의 전깃줄의 개수가 주어진다. 전깃줄의 개수는 100 이하의 자연수이다. 둘째 줄부터 한 줄에 하나씩 전깃줄이 A전봇대와 연결되는 위치의 번호와 B전봇대와 연결되는 위치의 번호가 차례로 주어진다. 위치의 번호는 500 이하의 자연수이고, 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다.

출력
첫째 줄에 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 출력한다. */

#include <iostream>
#include <algorithm>


using namespace std;


void Make_LIS(int *nums, pair<int, int> **dp_increase, int N)
{
    int j, right0, right1;
    dp_increase[1][0] = make_pair(1, nums[1]);
    dp_increase[1][1] = make_pair(0, -1);

    for (int i = 2; i <= N; i++)
    {
        if (dp_increase[i - 1][0].first == dp_increase[i - 1][1].first)
        {
            dp_increase[i][1] = (dp_increase[i - 1][0].second < dp_increase[i - 1][1].second) ? dp_increase[i - 1][0] : dp_increase[i - 1][1];
        }
        else
        {
            dp_increase[i][1] = (dp_increase[i - 1][0].first > dp_increase[i - 1][1].first) ? dp_increase[i - 1][0] : dp_increase[i - 1][1];
        }

        dp_increase[i][0] = make_pair(1, nums[i]);
        for (j = i - 1; j >= 1; j--)
        {

            if (j + 1 <= dp_increase[i][0].first)
                break;
            right0 = dp_increase[j][0].second;
            right1 = dp_increase[j][1].second;
            if (nums[i] > right0 && dp_increase[j][0].first + 1 > dp_increase[i][0].first)
            {
                dp_increase[i][0].first = dp_increase[j][0].first + 1;
            }
            if (nums[i] > right1 && dp_increase[j][1].first + 1 > dp_increase[i][0].first)
            {
                dp_increase[i][0].first = dp_increase[j][1].first + 1;
            }
        }
    }
}

bool compare_pair(pair<int,int> a, pair<int,int> b ) {
    return a.first < b.first;
}

int main(void) 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, tmp1, i, tmp2;
    cin >> N;
    pair<int,int> **dp_increase= new pair<int,int>*[N+1];
    pair<int,int> *wires = new pair<int,int>[N+1];
    
    int *nums = new int[N+1];
    int *nums_reversed = new int[N+1];
    for(i = 1; i<=N; i++) {
        dp_increase[i] = new pair<int,int>[2];
        cin >> tmp1 >> tmp2;
        wires[i] = make_pair(tmp1,tmp2);
    }

    // //A기준 정렬 후, B에서 나타나는 최대 부분 수열만큼 N에서 빼준다.

    sort(wires+1, wires+N+1, compare_pair);
    for(i = 1; i<=N; i++) {
        nums[i] = wires[i].second;
    }
    Make_LIS(nums, dp_increase, N);
    cout << N - max(dp_increase[N][0].first, dp_increase[N][1].first);
}
