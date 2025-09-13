/*
KOI 중학교에는 N개의 학급이 있으며, 각 학급의 학생 수는 모두 M명으로 구성된다. 이 중학교에서는 체육대회에 새로운 종목의 경기를 추가하였다.
 이 경기에 대해 모든 학생들은 저마다의 능력을 나타내는 능력치를 가지고 있으며, 이 능력치는 모든 학생이 서로 다르다.

이 경기는 한반에서 한 명의 대표선수를 선발하여 치른다. 경기의 형평성을 위하여, 각각의 반에서 대표로 선발된 모든 학생들의 능력치 중
 최댓값과 최솟값의 차이가 최소가 되도록 선수를 선발하려고 한다. 예를 들어, N=3, M=4인 경우 학생들의 능력치가 1반=[12, 16, 67, 43],
 2반=[7, 17, 68, 48], 3반=[14, 15, 77, 54]로 주어질 때, 각 학급으로부터 능력치 16, 17, 15를 가진 학생을 각각 선택하면,
 최댓값과 최솟값의 차이가 17-15=2로 최소가 된다.

대표로 선발된 모든 학생들 능력치의 최댓값과 최솟값 차이가 최소가 되는 경우의 값을 출력하는 프로그램을 작성하시오.

입력
입력의 첫 번째 줄에는 학급의 수를 나타내는 N과 각 학급의 학생의 수를 나타내는 M이 하나의 빈칸을 사이에 두고 주어진다. 단, 1 ≤ N, M ≤ 1,000이다.
 두 번째 줄부터 N개의 줄에는 각 줄마다 한 학급 학생들의 능력치를 나타내는 M개의 양의 정수가 하나의 빈칸을 사이에 두고 주어진다. 능력치는 0이상 10^9이하이다.

출력
대표로 선발된 모든 학생들 능력치의 최댓값과 최솟값 차이가 최소가 되는 경우의 값을 하나의 정수로 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;

int N, M;

int class_students[1001][1001];
int student_pointer[1001]; // 0반~N-1반의 학생 위치 포인터 -> 처음엔 0으로 고정
int min_class_pointer;
int max_class_pointer;



int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> class_students[i][j];
        }
        sort(class_students[i], class_students[i] + M);
    }

    // 일단 각 교실별로 정렬을 때려주고,
    // 투 포인터로 되나?? 음,, 투 포인터라면 최소 최대를 각각 포인터로 두면 될 듯.
    // 0, 1, 2, ,,, N-1반까지 있다고 하면, 각 반마다 포인터를 둔다.
    // 포인터가 가리키는 값들 중 최소를 찾아서 그 ㅅㄲ만 앞으로 보내주면 된다.


    int ans = 0x7fffffff;
    while(student_pointer[min_class_pointer] < M) {
        int min_value = 2100000000;
        int max_value = -1;
        for (int i = 0; i < N; ++i) {
            if(class_students[i][student_pointer[i]] < min_value) {
                min_value = class_students[i][student_pointer[i]];
                min_class_pointer = i;
            }
            if(class_students[i][student_pointer[i]] >= max_value) { // 등호를 포함시켜야 두 포인터가 같은 값이 되지 않는다.
                max_value = class_students[i][student_pointer[i]];
                max_class_pointer = i;
            }
        }
        //cout << min_value << " " << max_value << endl;
        ans = min(ans, max_value - min_value);
        student_pointer[min_class_pointer]++;
    }
    cout << ans;
}