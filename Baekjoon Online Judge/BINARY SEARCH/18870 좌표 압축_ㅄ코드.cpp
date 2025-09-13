/*
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표 Xj의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

입력
첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

출력
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    map<int, int> nums_to_compressed{};
    set<int> nums_set{};
    vector<int> nums_list_original{};
    vector<int> nums_list{};
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        nums_list_original.push_back(tmp);
        nums_set.insert(tmp);
        nums_list.push_back(tmp);
    }
    std::sort(nums_list.begin(), nums_list.end());
    int cumulated_count = 0;
    for (auto i = nums_set.begin(); i != nums_set.end(); ++i) {
        nums_to_compressed[*i] = cumulated_count;
        cumulated_count++;
    }

    for(int i: nums_list_original) {
        cout << nums_to_compressed[i] << " ";
    }






}