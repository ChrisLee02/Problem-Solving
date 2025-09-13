/* 철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.

창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면,
 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.
 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며,
 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지,
 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다.
둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다.
 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토,
 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

토마토가 하나 이상 있는 경우만 입력으로 주어진다.

출력
여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고,
 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
*/
#include <bits/stdc++.h>


using namespace std;

class Box {
public:
    int **map;
    int **newMap;
    queue<tuple<int, int, int>> tomatoes;
    int time;
    int answer;
    int N, M;

    void initBox(int N_, int M_) {
        tomatoes = queue<tuple<int, int, int>>();
        map = new int *[N_];
        newMap = new int *[N_];
        for (int i = 0; i < N_; i++) {
            map[i] = new int[M_];
            newMap[i] = new int[M_];
            for (int j = 0; j < M_; j++) {
                cin >> map[i][j];
                if (map[i][j] == 1) {
                    tomatoes.push(tuple<int, int, int>(i, j, 0));
                }
                newMap[i][j] = -1;
            }
        }
        time = 0;
        this->N = N_;
        this->M = M_;
    }

    void proceed_new() {
        while (!tomatoes.empty()) {
            tuple<int, int, int> tomato = tomatoes.front();
            tomatoes.pop();
            int i = get<0>(tomato);
            int j = get<1>(tomato);
            time = get<2>(tomato);
            //cout << i << " " << j << " " << time << endl;
            if (i - 1 >= 0 && map[i - 1][j] == 0) {
                map[i - 1][j] = 1;
                tomatoes.push(tuple<int,int,int>(i-1, j, time+1));
            }
            if (i + 1 < N && map[i + 1][j] == 0) {
                map[i + 1][j] = 1;
                tomatoes.push(tuple<int,int,int>(i+1, j, time+1));
            }
            if (j - 1 >= 0 && map[i][j - 1] == 0) {
                map[i][j-1] = 1;
                tomatoes.push(tuple<int,int,int>(i, j-1, time+1));
            }
            if (j + 1 < M && map[i][j + 1] == 0) {
                map[i][j+1] = 1;
                tomatoes.push(tuple<int,int,int>(i, j+1, time+1));
            }

            /*for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    cout << map[i][j] << " ";
                }
                cout<<endl;
            }*/

        }

        if (!isSuccess()) {
            time = -1;
        }

    }

    bool isSuccess() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    void getNewMap() {

        for (int i = 0; i < N; i++) { // 업데이트 로직
            for (int j = 0; j < M; j++) {
                if (map[i][j] == -1 || map[i][j] == 1) {
                    newMap[i][j] = map[i][j];
                    continue;
                }
                newMap[i][j] = 0;

                if (i - 1 >= 0 && map[i - 1][j] == 1) newMap[i][j] = 1;

                if (j - 1 >= 0 && map[i][j - 1] == 1) newMap[i][j] = 1;

                if (i + 1 < N && map[i + 1][j] == 1) newMap[i][j] = 1;

                if (j + 1 < M && map[i][j + 1] == 1) newMap[i][j] = 1;
            }
        }
    }

    void updateMap() {
        for (int i = 0; i < N; i++) { // 지도 업데이트
            for (int j = 0; j < M; j++) {
                map[i][j] = newMap[i][j];
                // cout << map[i][j] << " ";
            }
            //cout<<endl;
        }
    }

    bool proceed() { // 끝나면 true 반환

        getNewMap();
        time++;


        bool isEnd = true;
        for (int i = 0; i < N; i++) { // 변화 있는지 체크
            for (int j = 0; j < M; j++) {
                if (map[i][j] != newMap[i][j]) {
                    isEnd = false;
                    break;
                }
            }
            if (!isEnd) break;
        }

        updateMap();

        return isEnd;
    }

    /*bool isAble() { //-1만 있는 경우는 주어지지 않음
        bool result = false;
        for(int i = 0; i<N; i++) {
            for(int j = 0; j<M; j++) {
                if(map[i][j] == 1) {
                    result = true;
                    break;
                }
            }
            if(result) break;
        } // 1이 하나라도 있어야 함.

        if(!result) return result;

        for(int i = 0; i<N; i++) {
            for(int j = 0; j<M; j++) {
                bool blocked = true;
                if(i-1>=0 && map[i-1][j]==-1) blocked = blocked & true;
                if(j-1>=0 && map[i][j-1]==-1) blocked = blocked & true;
                if(i+1<N && map[i+1][j]==-1) blocked = blocked & true;
                if(j+1<N && map[i][j+1]==-1) blocked = blocked & true;

                if(map[i][j] == 1) {
                    result = true;
                    break;
                }
            }
        } // -1로 둘러싸인 부분 검증


        return true;


    }
    */


};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N_, M_, tmp;
    cin >> M_ >> N_; // 가로, 세로
    Box box = Box();
    box.initBox(N_, M_);
    box.proceed_new();
    cout << box.time;

    /*while (true) {
        //    cout<<"Tlqkf"<<endl;
        bool isEnd = box.proceed();
        if (isEnd) {
            if (box.isSuccess()) cout << box.time - 1;
            else cout << -1;
            break;
        }
    }
*/

}