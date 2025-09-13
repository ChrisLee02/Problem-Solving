/*
지민이는 전체 페이지의 수가 N인 책이 하나 있다. 첫 페이지는 1 페이지이고, 마지막 페이지는 N 페이지이다.
 각 숫자가 전체 페이지 번호에서 모두 몇 번 나오는지 구해보자.

입력
첫째 줄에 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 0이 총 몇 번 나오는지, 1이 총 몇 번 나오는지, ..., 9가 총 몇 번 나오는지를 공백으로 구분해 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;

map<int, long long> num_count{};
int selected[10]; // 각 자리에 택한 숫자를 저장
int N_disassembled[10];
int N;

int pow_of_ten(int n) {
    int i = 1;
    for (int j = 0; j < n; ++j) {
        i = i*10;
    }
    return i;
}

int get_digit(int n) {
    int digit = 0;
    while(n>0) {
        digit++;
        N_disassembled[digit] = n%10;
        n = n/10;

    }
    return digit;
}


void fun_zero(int cur_digit) {
    if(cur_digit < 1 ) {
        return;
    }
    if(cur_digit == 1) {
        for (int j = 1; j <= 9; ++j) {
            num_count[j] = num_count[j] + 1;
        }
        return;
    }

    for (int i = 1; i <= 9; ++i) {
        num_count[i] = num_count[i] + pow_of_ten(cur_digit-1);
        for (int j = 0; j <= 9; ++j) {
            num_count[j] = num_count[j] + pow_of_ten(cur_digit-2)*(cur_digit-1);
        }
    }

    fun_zero(cur_digit - 1);

}

void fun_equal(int cur_digit) {
    if(cur_digit < 1 ) {
        return;
    }
    if(cur_digit == 1) {
        for (int i = 0; i <= N_disassembled[cur_digit]; ++i) {
            num_count[i] = num_count[i] + 1;
        }
        return;
    }

    num_count[N_disassembled[cur_digit]] = num_count[N_disassembled[cur_digit]] + N % pow_of_ten(cur_digit-1) + 1;

    for (int i = 0; i < N_disassembled[cur_digit]; ++i) {
        num_count[i] = num_count[i] + pow_of_ten(cur_digit-1);
        for (int j = 0; j <= 9; ++j) {
            num_count[j] = num_count[j] + pow_of_ten(cur_digit-2)*(cur_digit-1);
        }
    }

    fun_equal(cur_digit - 1);

}

int main()
{
    cin >> N;
    int digit = get_digit(N);
    //std::reverse(N_disassembled.begin(), N_disassembled.end());
    /*for (int i = digit; i >= 1; --i) {
        cout<< N_disassembled[i];
    }*/
    for (int i = 0; i <= 9; ++i) {
        num_count[i] = 0;
    }
    //백트래킹 혹은 각 자리수 별로 경우의 수 세기
    //4자리 수로 생각해보자. 0~7571인 경우에 1XXX꼴의 수에서 천자리에서 1은 1000번, 그 아래로는 0~9가 300번씩 등장한다.
    //6xxx까지 적용 가능하므로 7로 시작하는 경우, 0으로 시작하는 경우만 특별하게 다뤄주면 됨.
    for (int i = 1; i < N_disassembled[digit]; ++i) { // 1XXX ~ 6XXX까지에 해당하는 케이스
        num_count[i] = num_count[i] + pow_of_ten(digit-1);
        for (int j = 0; j <= 9; ++j) {
            num_count[j] = num_count[j] + pow_of_ten(digit-2)*(digit-1);
        }
    }

    /*for (int i = 0; i <= 9; ++i) {
        cout << num_count[i] << " ";
    }
    cout << endl;*/

    fun_zero(digit-1);

    /*for (int i = 0; i <= 9; ++i) {
        cout << num_count[i] << " ";
    }
    cout << endl;*/

    num_count[N_disassembled[digit]] = num_count[N_disassembled[digit]] + (N % pow_of_ten(digit-1)) + 1;
    fun_equal(digit-1);

    for (int i = 0; i <= 9; ++i) {
        cout << num_count[i] << " ";
    }
}