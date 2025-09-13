/* https://www.acmicpc.net/problem/15652
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다. */

/* https://www.acmicpc.net/problem/15652
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void NandM(vector<int> List, int N, int M, int i) {

    // if(i>*(List.end() - 1) ) { //List.end() -> 맨 끝 데이터 바로 뒤 포인터 값임. 따라서 List.end - 1에 참조 붙이면 끝값
    //     return;
    // }
    List.push_back(i);
    if(List.size()==M) {
        for(int j = 0; j<M; j++) cout << List[j] << " ";
        cout<<'\n';
        return; 
    }
    
    for(int j = i; j<=N; j++) {
        NandM(List, N, M, j);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int N,M;
    cin >> N >> M;
    vector<int> List;
    for(int i = 1; i<=N; i++)
    NandM(List, N, M, i);
}