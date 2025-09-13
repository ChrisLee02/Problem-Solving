/* https://www.acmicpc.net/problem/15654
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열
입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void NandM(vector<int> List,vector<int> List2, int N, int M, int i) {

    
     if(find(List2.begin(),List2.end(),List[i]) != List2.end()  ) { //중복 존재 시
        return;
    }
    List2.push_back(List[i]);
    if(List2.size()==M) {
        for(int j = 0; j<M; j++) cout << List2[j] << " ";
        cout<<'\n';
        return; 
    }
    
    for(int j = 0; j<N; j++) {
        NandM(List,List2, N, M, j);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int N,M,tmp;
    cin >> N >> M;
    vector<int> List;
    vector<int> List2;
    for(int i = 1; i<=N; i++)
    {
        cin >> tmp;
        List.push_back(tmp);
    }
    sort(List.begin(),List.end());
    for(int i = 0; i<N; i++)
    {
        NandM(List,List2, N, M, i);
    }
    
}