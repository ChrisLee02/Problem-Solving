/*
N개의 수 A1, A2, ..., AN과 L이 주어진다.

Di = A_(i-L+1) ~ A_i 중의 최솟값이라고 할 때, D에 저장된 수를 출력하는 프로그램을 작성하시오. 이때, i ≤ 0 인 Ai는 무시하고 D를 구해야 한다.

입력
첫째 줄에 N과 L이 주어진다. (1 ≤ L ≤ N ≤ 5,000,000)

둘째 줄에는 N개의 수 Ai가 주어진다. (-10^9 ≤ Ai ≤ 10^9)

출력
첫째 줄에 Di를 공백으로 구분하여 순서대로 출력한다.
 */

// pop을 더 빡세게 시켜서 사이즈를 줄여야할듯.

#include <bits/stdc++.h>

using namespace std;

// 스택, 큐, 덱은 정렬된 상태를 유지하는 경우에 문제가 간단해진다면 사용할 수 있다.
// 정렬된 상태에서 어떤 쪽의 값을 접근해야 되는가? 요것에 대한 대답 = 셋 중에 어떤 자료구조를 택할 것인가가 된다

// 오른쪽에 더 작은 수가 뜨는 순간, 그 앞의 큰 숫자들은 의미를 잃어버림. 얘네를 pop_back 해도 된다는 뜻이다.
// 정해진 구간에서 오름차순을 유지하면 '맨 앞의' 값이 최솟값이 됨. 따라서 이건 양방향 접근이 필요한 덱을 사용한다.
// 기본적인 !deque.empty() && 체크같은걸 신경쓰자.


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, L, tmp;
    cin >> N >> L;
    int *D = new int[N + 1];
    deque<pair<int, int>> deque{}; // id, value

    //
    int allowance = L;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;

        if( !deque.empty() && i-deque.front().first == L) {
            deque.pop_front();
        }


        while (!deque.empty() && deque.back().second >= tmp) {
            deque.pop_back();
            //allowance++;
        }

        deque.emplace_back(i, tmp);

        D[i] = deque.front().second;

    }



    for (int i = 1; i <= N; i++) {
        cout << D[i] << " ";
    }


}