/*
총 25명의 여학생들로 이루어진 여학생반은 5×5의 정사각형 격자 형태로 자리가 배치되었고, 얼마 지나지 않아 이다솜과 임도연이라는
 두 학생이 두각을 나타내며 다른 학생들을 휘어잡기 시작했다. 곧 모든 여학생이 ‘이다솜파’와 ‘임도연파’의 두 파로 갈라지게 되었으며,
 얼마 지나지 않아 ‘임도연파’가 세력을 확장시키며 ‘이다솜파’를 위협하기 시작했다.

위기의식을 느낀 ‘이다솜파’의 학생들은 과감히 현재의 체제를 포기하고, ‘소문난 칠공주’를 결성하는 것이 유일한 생존 수단임을 깨달았다. ‘
 소문난 칠공주’는 다음과 같은 규칙을 만족해야 한다.

이름이 이름인 만큼, 7명의 여학생들로 구성되어야 한다.
강한 결속력을 위해, 7명의 자리는 서로 가로나 세로로 반드시 인접해 있어야 한다.
화합과 번영을 위해, 반드시 ‘이다솜파’의 학생들로만 구성될 필요는 없다.
그러나 생존을 위해, ‘이다솜파’가 반드시 우위를 점해야 한다. 따라서 7명의 학생 중 ‘이다솜파’의 학생이 적어도 4명 이상은 반드시 포함되어 있어야 한다.
여학생반의 자리 배치도가 주어졌을 때, ‘소문난 칠공주’를 결성할 수 있는 모든 경우의 수를 구하는 프로그램을 작성하시오.

입력
'S'(이다‘솜’파의 학생을 나타냄) 또는 'Y'(임도‘연’파의 학생을 나타냄)을 값으로 갖는 5*5 행렬이 공백 없이 첫째 줄부터 다섯 줄에 걸쳐 주어진다.

출력
첫째 줄에 ‘소문난 칠공주’를 결성할 수 있는 모든 경우의 수를 출력한다.
 */


//실패한 순간에만 백트래킹을 할 필요는 없다.

#include <bits/stdc++.h>
#define X first
#define Y second
#define Pair pair<int,int>

using namespace std;
char Board[6][6];
char Visit[6][6];
char Visit_permanent[6][6];
stack<Pair> S{};
set<set<Pair>> Log_Set{};
set<Pair> new_Log{};
int cnt_S;
int cnt_Y;

int ans = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fun() {
    if(cnt_Y>=4) {
        //cout << "CEX2" << endl;
        return;
    }
    if(cnt_Y + cnt_S == 7) {
        //cout << "CEX" << endl;
        if(cnt_Y>=4) {
            //cout << "CEX2" << endl;
            return;
        }

        if(Log_Set.find(new_Log) != Log_Set.end()) {
           // cout << "CEX3" << endl;
            return;
        }
       // cout << "CEX4" << endl;
        ans++;
        Log_Set.insert(new_Log);
        return;
    }


    Pair cur = S.top();

    for (int k = 0; k < 4; k++) {
        int nx = cur.X + dx[k];
        int ny = cur.Y + dy[k];

        if (nx >= 1 && nx <= 5 && ny >= 1 && ny <= 5 && !Visit[nx][ny] ) {
            Visit[nx][ny] = 1;
            // 1. 다음 좌표를 log에는 담고 stack에는 넣지 않는다. -> log, stack
            // 2. 다음 좌표를 log에도 담고 stack에도 담는다. -> log, not stack
            // 3. not log, not stack

            /*if(Board[nx][ny] == 'S') cnt_S++;
            else cnt_Y++;
            new_Log.emplace(nx,ny);
            S.emplace(nx,ny);

            fun();
            //여기서 스택을 한 번 쭉 빼면서 재탐색을 해야함.
            S.pop();
            //case 1
            fun();
            new_Log.erase(Pair(nx,ny));
            if(Board[nx][ny] == 'S') cnt_S--;
            else cnt_Y--;
            Visit[nx][ny] = 0;*/

            // =====폐기한다.
            //REVISED:
            //다음 좌표를 log에 담은 뒤, stack을 하나씩 pop하면서 fun을 재호출해준다. 언제까지? 스택 사이즈가 0일때까지
            //이걸 마친 후에 다음 좌표를 stack에 담고 탐색을 이어나간다.
            if(Board[nx][ny] == 'S') cnt_S++;
            else cnt_Y++;
            new_Log.emplace(nx,ny);
            stack<Pair> tmpStack{};
            while(!S.empty()) {
                tmpStack.push(S.top());
                fun();
                S.pop();
            }
            while(!tmpStack.empty()) {
                S.push(tmpStack.top());
                tmpStack.pop();
            }


            S.emplace(nx,ny);

            fun();

            S.pop();
            new_Log.erase(Pair(nx,ny));
            if(Board[nx][ny] == 'S') cnt_S--;
            else cnt_Y--;
            Visit[nx][ny] = 0;

        }

    }
}

int main()
{
    string tmp;
    for (int i = 1; i <=5; ++i) {
        cin >> tmp;
        for (int j = 1; j <=5; ++j) {
            Board[i][j] = tmp[j-1];
        }
    }

    for (int i = 1; i <=5; ++i) {
        for (int j = 1; j <=5; ++j) {

            new_Log = set<Pair>{};
            cnt_Y = 0;
            cnt_S = 0;
            if(Board[i][j] == 'Y') cnt_Y++;
            else cnt_S++;

            Visit[i][j] = 1;
            S.push(Pair(i,j));
            new_Log.emplace(i,j);

            fun();

            S.pop();
            new_Log.erase(Pair(i,j));
            Visit[i][j] = 0;

        }
    }
    /*for (set<Pair> set: Log_Set) {
        for (int i = 1; i <=5; ++i) {
            for (int j = 1; j <=5; ++j) {
                if(set.find(Pair(i,j)) == set.end()) {
                    cout << "  ";
                }
                else cout << Board[i][j] << " ";
            }
            cout << endl;
        }
        *//*for (Pair pair: set) {
            cout << pair.first << " " << pair.second << endl;
        }
        cout << endl;*//*
    }*/
    cout << ans;


}
