/*
N(5 ≤ N ≤ 1,000)개의 자연수들로 이루어진 집합 U가 있다. 이 중에서 적당히 세 수를 골랐을 때,
 그 세 수의 합 d도 U안에 포함되는 경우가 있을 수 있다. 이러한 경우들 중에서, 가장 큰 d를 찾으라.

예를 들어 {2, 3, 5, 10, 18}와 같은 집합이 있다고 하자. 2+3+5 = 10이 되고, 이 수는 집합에 포함된다.
 하지만 3+5+10 = 18이 되고, 이 경우가 세 수의 합이 가장 커지는 경우이다.

입력
첫째 줄에 자연수 N이 주어진다. 다음 N개의 줄에 차례로 U의 원소가 하나씩 주어진다. 주어진 U는 집합이 되므로 입력되는 두 수가 같아서는 안 된다.
 U의 원소는 200,000,000보다 작거나 같은 자연수이다. 답이 항상 존재하는 경우만 입력으로 주어진다.

출력
우리가 x번째 수, y번째 수, z번째 수를 더해서 k번째 수를 만들었다라고 하자. 위의 예제에서 2+3+5=10의 경우는 x, y, z, k가 차례로 1, 2, 3, 4가 되며,
 최적해의 경우는 2, 3, 4, 5가 된다. k번째 수가 최대가 되도록 하는 것이 목적이다. x, y, z, k가 서로 같아도 된다. 이때, k번째 수를 출력하면 된다.
 */

#include <bits/stdc++.h>

using namespace std;
// x+y의 가능한 값들을 미리 저장해두면 어떨까?
// z값을 고르는게 N이고 그에 대응하는 x+y를 찾는게 log(N^2), 충분하다.
// x+y 정렬하는데 N^2log(N^2), 이것도 ok.
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> x_plus_y{};
    vector<int> num_set{};
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        num_set.push_back(tmp);
    }

    std::sort(num_set.begin(), num_set.end());

    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            if(num_set[i] + num_set[j] < num_set[N-1]) x_plus_y.push_back(num_set[i] + num_set[j]);
        }
    }

    x_plus_y.erase(std::unique(x_plus_y.begin(), x_plus_y.end()), x_plus_y.end());
    std::sort(x_plus_y.begin(), x_plus_y.end());

    for (int i = N-1; i >= 1; --i) {
        for (int j = i-1; j >= 0; --j) {
            int target = num_set[i] - num_set[j];
            if(std::binary_search(x_plus_y.begin(), x_plus_y.end(),target)) {
                cout << num_set[i];
                return 0;
            }
        }
    }
}