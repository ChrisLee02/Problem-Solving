/* https://www.acmicpc.net/problem/18111
팀 레드시프트는 대회 준비를 하다가 지루해져서 샌드박스 게임인 ‘마인크래프트’를 켰다. 마인크래프트는 1 × 1 × 1(세로, 가로, 높이) 
크기의 블록들로 이루어진 3차원 세계에서 자유롭게 땅을 파거나 집을 지을 수 있는 게임이다.

목재를 충분히 모은 lvalue는 집을 짓기로 하였다. 하지만 고르지 않은 땅에는 집을 지을 수 없기 때문에 땅의 높이를 모두 동일하게 만드는
 ‘땅 고르기’ 작업을 해야 한다.

lvalue는 세로 N, 가로 M 크기의 집터를 골랐다. 집터 맨 왼쪽 위의 좌표는 (0, 0)이다. 우리의 목적은 이 집터 내의 땅의 높이를 일정하게
 바꾸는 것이다. 우리는 다음과 같은 두 종류의 작업을 할 수 있다.

좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다.
1번 작업은 2초가 걸리며, 2번 작업은 1초가 걸린다. 밤에는 무서운 몬스터들이 나오기 때문에 최대한 빨리 땅 고르기 작업을 마쳐야 한다.
 ‘땅 고르기’ 작업에 걸리는 최소 시간과 그 경우 땅의 높이를 출력하시오.

단, 집터 아래에 동굴 등 빈 공간은 존재하지 않으며, 집터 바깥에서 블록을 가져올 수 없다. 또한, 작업을 시작할 때 인벤토리에는 B개의
 블록이 들어 있다. 땅의 높이는 256블록을 초과할 수 없으며, 음수가 될 수 없다.

입력
첫째 줄에 N, M, B가 주어진다. (1 ≤ M, N ≤ 500, 0 ≤ B ≤ 6.4 × 107)
둘째 줄부터 N개의 줄에 각각 M개의 정수로 땅의 높이가 주어진다. (i + 2)번째 줄의 (j + 1)번째 수는 좌표 (i, j)에서의 땅의 높이를 나타낸다.
땅의 높이는 256보다 작거나 같은 자연수 또는 0이다.
출력
첫째 줄에 땅을 고르는 데 걸리는 시간과 땅의 높이를 출력하시오. 답이 여러 개 있다면 그중에서 땅의 높이가 가장 높은 것을 출력하시오.
 */

// (배낭 + 땅 총 블럭)/(N*M) 이 땅 높이의 상한선이 된다는 점을 일단 알 수 있음.
// 놓는 것이 파는 것보다 시간이 덜 걸린다.
// 그러면 상한선 두고, 이진탐색을 해도 될지도? -> 상한선과 하한선이 정해지면? 이진 탐색을 쓰기 수월하구나?
// 조건 내에서 최솟값 구하는 공식만 알 수 있으면 가능함.
// 높이를 상수로 준 다음 그때 시간의 최솟값을 구하는건 생각보다 간단함. 각 블럭별로 수행해야 하는 시간량만 따져주면 되기 때문.

//첫째 줄에 땅을 고르는 데 걸리는 시간과 땅의 높이를 출력하시오. 답이 여러 개 있다면 그중에서 땅의 높이가 가장 높은 것을 출력하시오
// -> pair 사용하면 해결될 문제임.
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stack>
#include <algorithm>

using namespace std;

int countBoard(int **Board, int N, int M, int height) {
    int time = 0;
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) {
            if(height - Board[i][j] > 0) { // 보드 위로 쌓는 상황
                time = time + height - Board[i][j];
            }
            else {
                time = time + 2*(Board[i][j] - height);
            }
        }
    }
    return time;
}

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,M,B,tmp;
    pair<int,int> answerTime; // time, height
    long long sum,left,right,mid;
    int mean;
    cin >> N >> M >> B;
    sum = B;
    int **Board = new int*[N];
    for(int i = 0; i<N; i++) {
        Board[i] = new int[M];
    }
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<M; j++) {
            cin>>tmp;
            sum = sum+tmp;
            Board[i][j] = tmp;
        }
    }
    mean = sum/(N*M);
    // left = 0;
    // right = mean;
    // while(left<=right) {
    //     mid = (left+right)/2;

    // }
    answerTime = make_pair(countBoard(Board,N,M, mean), mean); 
    for(int i = mean-1; i>=0; i--) {
        tmp = countBoard(Board, N, M, i);
        if(tmp<answerTime.first) answerTime = make_pair(tmp, i);
    }
    cout << answerTime.first<<" "<<answerTime.second;
}