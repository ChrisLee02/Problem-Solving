/*
문제
음이 아닌 정수 X의 자릿수가 가장 큰 자릿수부터 작은 자릿수까지 감소한다면, 그 수를 감소하는 수라고 한다. 예를 들어, 321과 950은 감소하는 수지만,
322와 958은 아니다. N번째 감소하는 수를 출력하는 프로그램을 작성하시오. 0은 0번째 감소하는 수이고, 1은 1번째 감소하는 수이다.
 만약 N번째 감소하는 수가 없다면 -1을 출력한다.

입력
첫째 줄에 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 N번째 감소하는 수를 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;

bool found = false;
int N;
int cnt = -1;
int cur_digit;

void fun(int n, int prev_num, string made_number) { // n자리수의 감소하는 수를 오름차순으로 찾는다. NOLINT(performance-unnecessary-value-param)
    if(cur_digit == n+1) {
        cnt++;
        if(cnt == N) {
            found = true;
            cout << made_number;
        }
        return;
    }
    for (int i = 0; i < prev_num; ++i) {
        cur_digit++;
        fun(n, i, made_number + char('0' + i));
        cur_digit--;
    }
}

int main()
{
    cin >> N;

    for (int i = 1; i <= 10; ++i) { //9876543210으로 10자리까지 가능하다.
        cur_digit = 1;
        fun(i, 10, "");
        if(found) break;
    }

    if(!found) cout << -1;
}