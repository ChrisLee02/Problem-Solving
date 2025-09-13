/* 1107 리모컨
수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼이 고장났다.
리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다.
채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.
수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오.

수빈이가 지금 보고 있는 채널은 100번이다.

입력
첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000)이 주어진다.
둘째 줄에는 고장난 버튼의 개수 M (0 ≤ M ≤ 10)이 주어진다.고장난 버튼이 있는 경우에는 셋째 줄에는 고장난 버튼이 주어지며, 같은 버튼이 여러 번 주어지는 경우는 없다.
출력
첫째 줄에 채널 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지를 출력한다.
*/
#include <bits/stdc++.h>

#define INF 999999

using namespace std;

int abs_sub(int a, int b) {
    return a>b ? a-b : b-a;
}


int main()
{
    int N, M, tmp;
    int answer1, answer2, answer3;
    set<int> buttons = {0,1,2,3,4,5,6,7,8,9};
    cin >> N >> M;
    for(int i = 0; i<M; i++) {
        cin >> tmp;
        buttons.erase(tmp);
    }
    vector<int> button_sorted(buttons.size());

    copy(buttons.begin(), buttons.end(), button_sorted.begin());
    sort(button_sorted.begin(), button_sorted.end());


    answer1 = abs_sub(N, 100);
    answer2 = INF;
    answer3 = INF;
    for(int i = N; i<=1000000 ; i++) {
        set<int> target_decomposed = set<int>();
        int count=0;
        if(i==0) {
            target_decomposed.insert(0);
            count++;
        }
        else {
            int tmp = i;
            while(tmp>0) {
                target_decomposed.insert(tmp%10);
                tmp=tmp/10;
                count++;
            }
        }

        bool includes = true;
        for(auto i : target_decomposed) {
            if(std::find(button_sorted.begin(), button_sorted.end(),i)==button_sorted.end()) {
                includes = false;
                break;
            }
        }

        if(includes){
            answer2 = count + abs_sub(i,N);
            break;
        }
    }

    for(int i = N-1; i>=0; i--) {
        set<int> target_decomposed = set<int>();
        int count=0;
        if(i==0) {
            target_decomposed.insert(0);
            count++;
        }
        else {
            int tmp = i;
            while(tmp>0) {
                target_decomposed.insert(tmp%10);
                tmp=tmp/10;
                count++;
            }
        }

        bool includes = true;
        for(auto i : target_decomposed) {
            if(std::find(button_sorted.begin(), button_sorted.end(),i)==button_sorted.end()) {
                includes = false;
                break;
            }
        }

        if(includes){
            answer3 = count + abs_sub(i,N);
            break;
        }

    }
    cout << min(min(answer1, answer2),answer3);



    // case 1: +-버튼만 써서 도달하는 것
    // case 2: 숫자 버튼과 +-버튼 혼용 - 같은 자리 내에서
    // 2-1: 큰 숫자 중 가장 가까운 것 -> 9 위에 10이 있는걸 어떻게 처리할까
    // 2-2: 작은 숫자 중 가장 가까운 것 -> 1 밑에 0이 있는걸 어떻게 처리할까


}