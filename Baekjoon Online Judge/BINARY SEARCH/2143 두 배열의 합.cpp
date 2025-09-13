/*
한 배열 A[1], A[2], …, A[n]에 대해서, 부 배열은 A[i], A[i+1], …, A[j-1], A[j] (단, 1 ≤ i ≤ j ≤ n)을 말한다.
 이러한 부 배열의 합은 A[i]+…+A[j]를 의미한다. 각 원소가 정수인 두 배열 A[1], …, A[n]과 B[1], …, B[m]이 주어졌을 때,
 A의 부 배열의 합에 B의 부 배열의 합을 더해서 T가 되는 모든 부 배열 쌍의 개수를 구하는 프로그램을 작성하시오.

예를 들어 A = {1, 3, 1, 2}, B = {1, 3, 2}, T=5인 경우, 부 배열 쌍의 개수는 다음의 7가지 경우가 있다.

T(=5) = A[1] + B[1] + B[2]
      = A[1] + A[2] + B[1]
      = A[2] + B[3]
      = A[2] + A[3] + B[1]
      = A[3] + B[1] + B[2]
      = A[3] + A[4] + B[3]
      = A[4] + B[2]
입력
첫째 줄에 T(-1,000,000,000 ≤ T ≤ 1,000,000,000)가 주어진다. 다음 줄에는 n(1 ≤ n ≤ 1,000)이 주어지고, 그 다음 줄에 n개의 정수로 A[1], …, A[n]이 주어진다.
 다음 줄에는 m(1 ≤ m ≤ 1,000)이 주어지고, 그 다음 줄에 m개의 정수로 B[1], …, B[m]이 주어진다. 각각의 배열 원소는 절댓값이 1,000,000을 넘지 않는 정수이다.

출력
첫째 줄에 답을 출력한다. 가능한 경우가 한 가지도 없을 경우에는 0을 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> A{};
vector<int> B{};
vector<int> part_sum_A{};
vector<int> part_sum_B{};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,N,M;
    cin >> T;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp; cin>>tmp;
        A.push_back(tmp);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int tmp; cin >> tmp;
        B.push_back(tmp);
    }

    /*for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < M; ++i) {
        cout << B[i] << " ";
    }
    cout<<endl;*/

    for (int i = 0; i < N; ++i) {
        int sum = A[i];
        part_sum_A.push_back(sum);
        for (int j = i+1; j < N; ++j) {
            sum += A[j];
            part_sum_A.push_back(sum);
        }
    }
    for (int i = 0; i < M; ++i) {
        int sum = B[i];
        part_sum_B.push_back(sum);
        for (int j = i+1; j < M; ++j) {
            sum += B[j];
            part_sum_B.push_back(sum);
        }
    }

   /* for (int i = 0; i < part_sum_A.size(); ++i) {
        cout << part_sum_A[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < part_sum_B.size(); ++i) {
        cout << part_sum_B[i] << " ";
    }
    cout<<endl;
*/
    long long ans = 0;
    std::sort(part_sum_A.begin(), part_sum_A.end());
    std::sort(part_sum_B.begin(), part_sum_B.end());

   /* for (int i = 0; i < part_sum_A.size(); ++i) {
        cout << part_sum_A[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < part_sum_B.size(); ++i) {
        cout << part_sum_B[i] << " ";
    }
    cout<<endl;*/


    for (int i = 0; i < part_sum_A.size(); ++i) {
        int target = T - part_sum_A[i];
        ans += std::upper_bound(part_sum_B.begin(), part_sum_B.end(),target) -
                std::lower_bound(part_sum_B.begin(), part_sum_B.end(),target);
    }
    cout << ans;





}