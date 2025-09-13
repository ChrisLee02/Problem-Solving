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



pair<int, int> find_min(const deque<pair<int,int>> &a)
{
    pair<int, int> min = pair<int,int>(0, 2100000000);

    for (const auto & ptr : a) {
        if(min.second >= ptr.second) {
            min = ptr;
        }
    }
    return min;
}
bool icompare(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.second <= b.second)
        return true;
    else
        return false;
}

void print(const deque<pair<int, int>> &deque) {
    cout << "print ";
    for (const auto & ptr : deque) {
        cout << ptr.second <<" / ";
    }
    cout << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, L;
    cin >> N >> L;
    int *A = new int[N+1];

    int *D = new int[N+1];
    deque<pair<int, int>> deque{}; // id, value1
    pair<int, int> min = pair<int,int>(0, 2100000000);
    if(N<=L) {
        for(int i = 1; i<=N; i++) {
            int tmp;
            cin >> tmp;
            if(tmp <= min.second ) {
                min = pair<int,int>(i, tmp);
                deque = std::deque<pair<int,int>>();
            }
            deque.emplace_back(i, tmp);
            cout << min.second << " ";
        }
    }
    else {
        int allowance = 0;
        for(int i = 1; i<=L; i++) {
            int tmp;
            cin >> tmp;
            if(tmp <= min.second ) {
                min = pair<int,int>(i, tmp);
            }
            deque.emplace_back(i, tmp);
            cout << min.second << " ";

        //    print(deque);
        }
        for(int i = L+1; i<=N; i++) {
            int tmp;
            cin >> tmp;
            if(allowance>0) {
                allowance--;
            } else {
                deque.pop_front();
                min = *min_element(deque.begin(), deque.end(), icompare);
                cout << endl << i << ": " << min.first << " ===== " << min.second << endl;
                while(deque.front().first != min.first) {
                    allowance++;
                    deque.pop_front();
                }
            }
            /*12 3
            1 5 2 3 6 2 3 7 3 5 2 6*/
            if(tmp <= min.second ) {
                min = pair<int,int>(i, tmp);
                allowance = allowance + deque.size();
                deque = std::deque<pair<int,int>>();
            }
            deque.emplace_back(i, tmp);
            cout << min.second << " ";
            //print(deque);
        }
    }

}