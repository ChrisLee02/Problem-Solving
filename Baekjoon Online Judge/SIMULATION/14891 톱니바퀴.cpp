/*
입력
첫째 줄에 1번 톱니바퀴의 상태, 둘째 줄에 2번 톱니바퀴의 상태, 셋째 줄에 3번 톱니바퀴의 상태, 넷째 줄에 4번 톱니바퀴의 상태가 주어진다.
 상태는 8개의 정수로 이루어져 있고, 12시방향부터 시계방향 순서대로 주어진다. N극은 0, S극은 1로 나타나있다.

다섯째 줄에는 회전 횟수 K(1 ≤ K ≤ 100)가 주어진다. 다음 K개 줄에는 회전시킨 방법이 순서대로 주어진다. 각 방법은 두 개의 정수로 이루어져 있고,
 첫 번째 정수는 회전시킨 톱니바퀴의 번호, 두 번째 정수는 방향이다. 방향이 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향이다.

출력
총 K번 회전시킨 이후에 네 톱니바퀴의 점수의 합을 출력한다. 점수란 다음과 같이 계산한다.

1번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 1점
2번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 2점
3번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 4점
4번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 8점
 */

#include <bits/stdc++.h>


using namespace std;

string wheel[5];
string wheelNext[5] = {"00000000","00000000","00000000","00000000","00000000"};

int K;

void update() {
    for (int i = 1; i <=4; ++i) {
        wheel[i] = wheelNext[i];
    }
}

void rotate(int cur, int direction) {
    if(direction == 1) { // 시계방향
        for (int i = 0; i < 8; ++i) {
            wheelNext[cur][(i+1)%8 ] = wheel[cur][i];
        }
    }

    else {
        for (int i = 0; i < 8; ++i) {
            wheelNext[cur][i] = wheel[cur][(i+1)%8];
        }
    }




}

void LeftPropagate(int cur, int direction) { //cur이 direction으로 회전한 기준, 그 왼쪽이 회전하는 동작을 구현.
    //cur의 [6]과 cur-1의 [2]를 비교한다.
    if (cur == 1) return;
    if(wheel[cur][6] != wheel[cur-1][2]) {
        rotate(cur-1, -1*direction);
        LeftPropagate(cur-1, -1*direction);
    }




}

void RightPropagate(int cur, int direction) {
    //cur의 [2]과 cur+1의 [6]를 비교한다.
    if (cur == 4) return;
    if(wheel[cur][2] != wheel[cur+1][6]) {
        rotate(cur+1, -1*direction);
        RightPropagate(cur+1, -1*direction);
    }
}
//[2], [6]을 각각 비교해줘야함.
int main() {
    cin >> wheel[1] >> wheel[2] >> wheel[3] >> wheel[4] >> K;
    for (int i = 1; i <=4; ++i) {
        wheelNext[i] = wheel[i];
    }
    int sum = 0;
    for (int i = 0; i < K; ++i) {
        int wheelNum, direction;
        cin >> wheelNum >> direction;
        rotate(wheelNum, direction);
        LeftPropagate(wheelNum, direction);
        RightPropagate(wheelNum, direction);
        update();
    }
    int tmp = 1;
    for (int i = 1; i <= 4; ++i) {
        //cout << wheel[i] << endl;
        if(wheel[i][0] == '1') sum = sum + tmp;
        tmp = tmp * 2;
    }
    cout << sum;
}
