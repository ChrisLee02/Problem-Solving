/*
기숙사에서 살고 있는 준규는 한 개의 멀티탭을 이용하고 있다. 준규는 키보드, 헤어드라이기, 핸드폰 충전기, 디지털 카메라 충전기 등 여러 개의
 전기용품을 사용하면서 어쩔 수 없이 각종 전기용품의 플러그를 뺐다 꽂았다 하는 불편함을 겪고 있다. 그래서 준규는 자신의 생활 패턴을 분석하여,
 자기가 사용하고 있는 전기용품의 사용순서를 알아내었고, 이를 기반으로 플러그를 빼는 횟수를 최소화하는 방법을 고안하여 보다 쾌적한 생활환경을 만들려고 한다.

예를 들어 3 구(구멍이 세 개 달린) 멀티탭을 쓸 때, 전기용품의 사용 순서가 아래와 같이 주어진다면,

키보드
헤어드라이기
핸드폰 충전기
디지털 카메라 충전기
키보드
헤어드라이기
키보드, 헤어드라이기, 핸드폰 충전기의 플러그를 순서대로 멀티탭에 꽂은 다음 디지털 카메라 충전기 플러그를 꽂기 전에 핸드폰충전기 플러그를 빼는 것이 최적일 것이므로
 플러그는 한 번만 빼면 된다.

입력
첫 줄에는 멀티탭 구멍의 개수 N (1 ≤ N ≤ 100)과 전기 용품의 총 사용횟수 K (1 ≤ K ≤ 100)가 정수로 주어진다. 두 번째 줄에는 전기용품의 이름이
 K 이하의 자연수로 사용 순서대로 주어진다. 각 줄의 모든 정수 사이는 공백문자로 구분되어 있다.

출력
하나씩 플러그를 빼는 최소의 횟수를 출력하시오.
 */

#include <bits/stdc++.h>

using namespace std;

map<int, queue<int>> num_to_seq{};
vector<int> seq{};
int multiTap[102]; // 0부터 N-1까지 사용
int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= K; ++i) {
        num_to_seq[i] = queue<int>();
    }


    for (int i = 0; i < K; ++i) {
        int tmp;
        cin >> tmp;
        seq.push_back(tmp);
        num_to_seq[tmp].push(i);
    }


    for (int i = 1; i <= K; ++i) {
        num_to_seq[i].push(99999);
    }


    if (N >= K) {
        cout << 0;
        return 0;
    }
    int seq_index = 0;
    for (int i = 0; i < N; seq_index++) {
        if (find(multiTap, multiTap + N, seq[seq_index]) == (multiTap + N)) {
            multiTap[i] = seq[seq_index];
            i++;
        }
        num_to_seq[seq[seq_index]].pop();
    }

    /*for (int i = 1; i <= K; ++i) {
        cout << i << ": ";
        while(!num_to_seq[i].empty()) {
            cout << num_to_seq[i].front();
            num_to_seq[i].pop();
        }
        cout << endl;
    }*/

    int cnt = 0;
    for (int i = seq_index; i < K; ++i) {

        if (find(multiTap, multiTap + N, seq[i]) != (multiTap + N)) {
           // cout << i << ": 할필요없음" << endl;
            num_to_seq[seq[i]].pop();
            continue;
        }
        int max_seq = -1;
        int selected_Tap;
        for (int j = 0; j < N; ++j) {
         //   cout << multiTap[j] << " " << num_to_seq[multiTap[j]].front() << endl;
            if (num_to_seq[multiTap[j]].front() > max_seq) {
                selected_Tap = j;
                max_seq = num_to_seq[multiTap[j]].front();
            }
        }
        cnt++;
       // cout << multiTap[selected_Tap] << endl;
        multiTap[selected_Tap] = seq[i];
        num_to_seq[seq[i]].pop();
    }

    cout << cnt;
}
