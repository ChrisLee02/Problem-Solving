/*
동호와 규완이는 212호에서 문자열에 대해 공부하고 있다. 김진영 조교는 동호와 규완이에게 특별 과제를 주었다.
 특별 과제는 특별한 문자열로 이루어 진 사전을 만드는 것이다. 사전에 수록되어 있는 모든 문자열은 N개의 "a"와 M개의 "z"로 이루어져 있다.
 그리고 다른 문자는 없다.사전에는 알파벳 순서대로 수록되어 있다.

규완이는 사전을 완성했지만, 동호는 사전을 완성하지 못했다. 동호는 자신의 과제를 끝내기 위해서 규완이의 사전을 몰래 참조하기로 했다.
 동호는 규완이가 자리를 비운 사이에 몰래 사전을 보려고 하기 때문에, 문자열 하나만 찾을 여유밖에 없다.

N과 M이 주어졌을 때, 규완이의 사전에서 K번째 문자열이 무엇인지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 세 정수 N, M, K가 순서대로 주어진다.
1 ≤ N, M ≤ 100
1 ≤ K ≤ 1,000,000,000
출력
첫째 줄에 규완이의 사전에서 K번째 문자열을 출력한다. 만약 규완이의 사전에 수록되어 있는 문자열의 개수가 K보다 작으면 -1을 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;

int combination[201][201];
string dictionary[101][101];


void init_combi() {
    combination[0][0] = 1;
    for (int i = 1; i <= 200; ++i) {
        combination[i][0] = 1;
        combination[i][i] = 1;
        for (int j = 1; j <= i - 1; ++j) {
            if (combination[i - 1][j] == INT32_MAX || combination[i - 1][j - 1] == INT32_MAX) {
                combination[i][j] = INT32_MAX;
                continue;
            }
            if (combination[i - 1][j] + combination[i - 1][j - 1] > 1000000000) {
                combination[i][j] = INT32_MAX;
                continue;
            }
            combination[i][j] = combination[i - 1][j] + combination[i - 1][j - 1];
        }
    }
}
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    init_combi();
    if(combination[N+M][N] != -1 && combination[N+M][N] < K ) {
        cout << -1;
        return 0;
    }

    /*
     M개의 z를 왼쪽부터 하나씩 제 위치를 찾아주는 식으로 알고리즘을 짠다.
     결정되지 않은 z의 개수를 x라고 두고, 위치를 결정하려는 z보다 오른쪽에 있는 a의 개수를 y라고 하자.
     그러면 z의 해당 위치에 대한 경우의 수는 x+y C x가 됨.
     z를 왼쪽으로 한 칸 더 밀면 x+y+1 C x가 됨. K값을 이만큼 차감하다가. 다음 조합값보다 K값이 더 작으면 거기서 z를 고정시킨다.
    */

    vector<int> pos_of_z_list{};
    int end_of_line = 1;
    for (int i = 1; i <= M; ++i) { // M개의 z에 대해 반복
        int pos_of_z = N + i;
        int count_of_x = 0;
        int count_of_z = M-i;
        for (pos_of_z = N + i; pos_of_z>=end_of_line; --pos_of_z) {
            //cout << i << "th z: "<< pos_of_z << " K val: " << K <<endl;

            //cout << "CEX" << combination[count_of_x+count_of_z][count_of_x] <<" " << count_of_x+count_of_z<<" " <<count_of_x << endl;

            if(K > combination[count_of_x+count_of_z][count_of_x]) {
                K = K - combination[count_of_x+count_of_z][count_of_x];
                count_of_x++;
            }

            else {
                break;
            }
        }

        pos_of_z_list.push_back(pos_of_z);
        end_of_line = pos_of_z + 1;
    }
    /*for (int i: pos_of_z_list) {
        cout << i << " ";
    }
    cout<<endl;*/

    for (int i = 1; i <= N+M; ++i) {
        if(std::find(pos_of_z_list.begin(), pos_of_z_list.end(),i) == pos_of_z_list.end() ) {
            cout<<"a";
        }
        else {
            cout<<"z";
        }
    }






}