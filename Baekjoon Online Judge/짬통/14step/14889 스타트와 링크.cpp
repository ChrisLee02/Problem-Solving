/* https://www.acmicpc.net/problem/14889
오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 축구는 평일 오후에 하고 의무 참석도 아니다. 축구를 하기 위해 
모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.
BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다. 능력치 Sij는 i번 사람과 j번 사람이 
같은 팀에 속했을 때, 팀에 더해지는 능력치이다. 팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 다를 수도 있으며, 
i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다. N=4이고, S가 아래와 같은 경우를 살펴보자.
i\j	1	2	3	4
1	 	1	2	3
2	4	 	5	6
3	7	1	 	2
4	3	4	5	 
예를 들어, 1, 2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 두 팀의 능력치는 아래와 같다.
스타트 팀: S12 + S21 = 1 + 4 = 5
링크 팀: S34 + S43 = 2 + 5 = 7
1, 3번이 스타트 팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 아래와 같다.
스타트 팀: S13 + S31 = 2 + 7 = 9
링크 팀: S24 + S42 = 6 + 4 = 10
축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다. 위의 예제와 같은 경우에는 1, 4번이 
스타트 팀, 2, 3번 팀이 링크 팀에 속하면 스타트 팀의 능력치는 6, 링크 팀의 능력치는 6이 되어서 차이가 0이 되고 이 값이 최소이다.
입력
첫째 줄에 N(4 ≤ N ≤ 20, N은 짝수)이 주어진다. 둘째 줄부터 N개의 줄에 S가 주어진다. 각 줄은 N개의 수로 이루어져 있고, 
i번 줄의 j번째 수는 Sij 이다. Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.
출력
첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력한다. */


#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int calculateAbility(long long *score, vector<int> &TeamPlayer, int **Board) { 
    //n: 몇 번째 선수가 들어왔는지, score: 현재 점수는 몇 점인지, TeamPlayer: 현재 갖고 있는 팀원은 누구인지
    //리턴할 값: n번째 선수가 들어오면서 더해지는 값
    int n = TeamPlayer.size();
    int sum = 0;
    int tmp1, tmp2;
    for(int i = 0; i<n-1; i++ ) {
        tmp1 =TeamPlayer[i];
        tmp2= TeamPlayer[n-1];
        sum = sum + Board[ TeamPlayer[i] ][ TeamPlayer[n-1] ];
        sum = sum + Board[ TeamPlayer[n-1] ][  TeamPlayer[i] ];
    }
    return sum;
}

void findMindiff_SimpleDFS(int N, int i,  long long *Min,  long long *score1,  long long *score2, 
vector<int> &Team1Player, bool *isPlayerChoosed, int **Board) { //가지치기 없이 일단 구현
    //선수 숫자, 몇번째 선수를 넣는 상황인지, 기존 최솟값, 1팀점수, 2팀점수, 이미 선택된 사람 배열, 점수판
    int tmp;
    vector<int> Team2Player;
    if(i>N) return;
    if(Team1Player.size() == N/2) {
        for(int i = 1, j = 1; i<=N/2; j++) { //i는 N/2번 카운팅 변수, j는 선수 집어넣는 변수
            if(isPlayerChoosed[j]) continue; //이미 1팀에서 가져갔으면 패쓰
            
            Team2Player.push_back(j);
            *score2 += calculateAbility(score2, Team2Player, Board); 
            i++;

        }
        tmp = abs( (*score1) - (*score2) );
        cout << "";
        if( tmp < *Min ) *Min = tmp;
        *score2 = 0;
        return;
    }
    Team1Player.push_back(i);
    isPlayerChoosed[i] = true;
    tmp = calculateAbility(score1, Team1Player, Board);
    *score1 += tmp;
    findMindiff_SimpleDFS(N,  i+1,  Min, score1,  score2, Team1Player, isPlayerChoosed, Board);
    Team1Player.pop_back();
    isPlayerChoosed[i] = false;
    *score1 -= tmp;
    findMindiff_SimpleDFS(N,  i+1,  Min, score1,  score2, Team1Player, isPlayerChoosed, Board);
}

int main(void)
{
    int N,tmp;
    cin >> N;
    int **Board = new int*[N+1]; //1번 선수는 1번 인덱스에 대응되도록 설정
    long long Min = 0; // 자명한 lowerbound가 없어서, 1~N/2 케이스로 초기화해야할 듯 
    //있음, Board값 전부 더하면 이새끼보단 무조건 작게 답이 나와야됨.
    //각 팀의 선수를 저장할 벡터가 필요함.
    long long score1 = 0;
    long long score2 = 0;
    vector<int> Team1Player;
    vector<int> Team2Player;
    //새로운 선수를 넣을 때, 기존 선수들을 순회하면서 s[i][j], s[j][i]를 더해준다.
    //선수들을 Bool 배열로 관리해줘야 할 듯.
    bool *isPlayerChoosed = new bool[N+1]; //마찬가지로 인덱스 대응 -> Team2에서 짬처리할 때 써먹을 놈입니다~
    fill_n(isPlayerChoosed, N+1, false); //초깃값은 모두 false로 초기화(변수명 의미대로)
    for(int i = 0; i<N+1; i++) {
        Board[i] = new int[N+1];
    }
    for(int i = 1; i<N+1; i++) {
        for(int j = 1; j<N+1; j++) {
            cin>>tmp;
            Min = Min + tmp;
            Board[i][j] = tmp;
        }
    }
    // for(int i = 1; i<N+1; i++) {
    //     for(int j = 1; j<N+1; j++) {
    //         cout << Board[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    findMindiff_SimpleDFS(N,  1,  &Min, &score1,  &score2, Team1Player, isPlayerChoosed, Board);
    cout << Min;
}

