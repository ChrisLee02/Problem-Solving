/*
길이가 N인 수열이 주어졌을 때, 그 수열의 합을 구하려고 한다. 하지만, 그냥 그 수열의 합을 모두 더해서 구하는 것이 아니라, 수열의 두 수를 묶으려고 한다.
 어떤 수를 묶으려고 할 때, 위치에 상관없이 묶을 수 있다. 하지만, 같은 위치에 있는 수(자기 자신)를 묶는 것은 불가능하다. 그리고 어떤 수를 묶게 되면,
 수열의 합을 구할 때 묶은 수는 서로 곱한 후에 더한다.

예를 들면, 어떤 수열이 {0, 1, 2, 4, 3, 5}일 때, 그냥 이 수열의 합을 구하면 0+1+2+4+3+5 = 15이다. 하지만, 2와 3을 묶고, 4와 5를 묶게 되면,
 0+1+(2*3)+(4*5) = 27이 되어 최대가 된다.

수열의 모든 수는 단 한번만 묶거나, 아니면 묶지 않아야한다.

수열이 주어졌을 때, 수열의 각 수를 적절히 묶었을 때, 그 합이 최대가 되게 하는 프로그램을 작성하시오.

입력
첫째 줄에 수열의 크기 N이 주어진다. N은 50보다 작은 자연수이다. 둘째 줄부터 N개의 줄에 수열의 각 수가 주어진다. 수열의 수는 -1,000보다 크거나 같고,
 1,000보다 작거나 같은 정수이다.

출력
수를 합이 최대가 나오게 묶었을 때 합을 출력한다. 정답은 항상 2^31보다 작다.
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> seq_pos{};
    vector<int> seq_neg{};
    bool zero_exist = false;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        if(tmp == 0) {
            zero_exist = true;
        }
        if(tmp > 0) {
            seq_pos.push_back(tmp);
        }
        if(tmp < 0) {
            seq_neg.push_back(tmp);
        }
    }
    int sum = 0;
    std::sort(seq_pos.begin(), seq_pos.end());
    std::sort(seq_neg.begin(), seq_neg.end());

    std::reverse(seq_pos.begin(), seq_pos.end());// pos는 내림차순
    int mul_1 = -1;
    for (int i = 0; i < seq_pos.size(); ++i) {
        if(seq_pos[i] == 1) {
            sum = sum + 1;
            continue;
        } // 1이면 곱하는거보다 더하는게 이득임.

        if(mul_1 == -1) {
            mul_1 = seq_pos[i];
        }
        else { //이전에 곱할 놈을 하나 구해놨다면
            sum = sum + mul_1 * seq_pos[i];
            mul_1 = -1;
        }
    }
    if(mul_1 != -1) { //홀수 개라서 못 곱하고 하나 남았다면 그냥 더해준다.
        sum = sum + mul_1;
    }

    mul_1 = 1;
    for (int i = 0; i < seq_neg.size(); ++i) {
        if(mul_1 == 1) {
            mul_1 = seq_neg[i];
        }
        else { //이전에 곱할 놈을 하나 구해놨다면
            sum = sum + mul_1 * seq_neg[i];
            mul_1 = 1;
        }
    }
    if(mul_1 != 1 && !zero_exist) { //홀수 개라서 못 곱하고 하나 남았다면, 0이 있으면 묶어주고 없으면 더해준다.
        sum = sum + mul_1;
    }

    cout << sum;

}
