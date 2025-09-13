/* https://www.acmicpc.net/problem/11053

수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 30, 50} 이고, 길이는 4이다.
입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(void) 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,j, right1, right0;
    cin >> N;
    pair<int,int> tmp;
    pair<int,int> **dp_increase = new pair<int,int>*[N+1]; // dp_increase[i][0/1] = int,int => 1번째~i번째까지 봤을 때 최적해 / i번째 포함미포함(0,1)
    //int, int = 길이, 가장 오른쪽의 값
    int *nums = new int[N+1];
    for(int i = 1; i<=N; i++) {
        cin >> nums[i];
        dp_increase[i] = new pair<int,int>[2];
    }
    dp_increase[1][0] = make_pair(1, nums[1]);
    dp_increase[1][1] = make_pair(0, -1);
    //사고 1. 수열을 증가하는 수열들의 단위로 분리한다면? -> 컷
    //사고 2. 역순으로 탐색한다면? 
    //사고 1, 2에서 억지로 i-1과의 점화식을 구하려고 한 것이 패인이었음
    //바로 전 요소에서 오름차순이 유지된다면, 점화식 관계가 성립
    //그렇지 않은 경우에는 1~i-1까지 탐색해가며 최적해를 완전탐색해야한다.
    for(int i = 2; i<=N; i++) {
        if(dp_increase[i-1][0].first == dp_increase[i-1][1].first) {
            dp_increase[i][1] = (dp_increase[i-1][0].second < dp_increase[i-1][1].second) ? dp_increase[i-1][0]: dp_increase[i-1][1];
            // 수열 길이가 같다면, 가장 오른쪽 값이 작은 놈이 더 유리함
        }
        else {
            dp_increase[i][1] = (dp_increase[i-1][0].first > dp_increase[i-1][1].first) ? dp_increase[i-1][0]: dp_increase[i-1][1];
            // 길이가 같지 않으면 수열 길이로 판단
        }
        //i번째를 포함하지 않는다면, i-1번째까지의 수열에서 최적해가 곧 i번째의 최적해임
        //이전 코드에서, isUpdated변수를 사용해서 갱신되었나 여부를 확인하였음.
        //그냥 dp_increase[i][0]에 기본값을 not updated상황에서의 값으로 설정해주면 더 간결하게 코드가 나오겠네?
        //씨발
        dp_increase[i][0] = make_pair(1,nums[i]);
        for (j = i - 1; j >= 1; j--)
        {
            // 현재 수열 길이랑, j의 위치를 ㅣㅂ교하면 break조건,continue조건 검토 가능
            if(j+1 <= dp_increase[i][0].first) break;
            // j의 위치 = dp_increase[j]에서 나올 수 있는 길이 값의 상한선
            //if( dp_increase[j][0].first + 1 <= dp_increase[i][0].first && dp_increase[j][1].first + 1 <= dp_increase[i][0].first) continue;
            // j번째에서 최적해가 갱신되지 않는다면 패쓰 => 두 차례에 걸쳐서 갱신하는 방식으로 가는게 더 깔끔할 듯.
            right0 = dp_increase[j][0].second;
            right1 = dp_increase[j][1].second; //바로 이전의 두 최적해에서 가장 오른쪽 값을 가져옴.
            if(nums[i] > right0 && dp_increase[j][0].first+1 > dp_increase[i][0].first ) { //오름차순 만족 & 길이 갱신조건 만족
                dp_increase[i][0].first = dp_increase[j][0].first+1;
            }
            if(nums[i] > right1 && dp_increase[j][1].first+1 > dp_increase[i][0].first ) { //오름차순 만족 & 길이 갱신조건 만족
                dp_increase[i][0].first = dp_increase[j][1].first+1;
            }
        }
        cout << dp_increase[i][0].first <<" "<< dp_increase[i][0].second << " " << dp_increase[i][1].first << " "<< dp_increase[i][1].second<<endl;
    }
    cout << max(dp_increase[N][0].first, dp_increase[N][1].first);
    
    //1000개짜리 1~1000의 배열과 주어진 수열을 비교한다?
    //바로 연속되는 수열을 찾으면, 얘네는 최적해가 된다.
}
