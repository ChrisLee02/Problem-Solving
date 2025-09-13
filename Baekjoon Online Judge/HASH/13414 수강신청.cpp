/*
국민대학교에서는 매 학기 시작 전 종합정보시스템에서 수강신청을 한다. 매 수강신청마다 아주 많은 학생들이 몰려 서버에 많은 부하가 가기 때문에,
 국민대학교에서는 수강신청 부하 관리 시스템을 도입하기로 결정하였다. 새로운 관리 시스템은 다음과 같은 방식으로 동작한다.

수강신청 버튼이 활성화 된 후, 수강신청 버튼을 조금이라도 빨리 누른 학생이 대기목록에 먼저 들어간다.
이미 대기열에 들어가 있는 상태에서 다시 수강신청 버튼을 누를 경우 대기목록의 맨 뒤로 밀려난다.
잠시 후 수강신청 버튼이 비활성화 되면, 대기목록에서 가장 앞에 있는 학생부터 자동으로 수강신청이 완료되며,
 수강 가능 인원이 꽉 찰 경우 나머지 대기목록은 무시하고 수강신청을 종료한다.

입력
 데이터는 표준 입력을 사용한다. 입력은 1개의 테스트 데이터로 구성된다. 입력의 첫 번째 줄에는 과목의 수강 가능 인원 K(1 ≤ K ≤ 100,000)와
 학생들이 버튼을 클릭한 순서를 기록한 대기목록의 길이 L(1 ≤ L ≤ 500,000)이 주어진다. 두 번째 줄부터 L개의 줄에는 수강신청을 버튼을 클릭한 학생의
 학번이 클릭 순서대로 주어진다. 학번은 8자리의 숫자로 이루어져 있다.

출력
출력은 표준 출력을 사용한다. 입력받은 데이터에 대해, 수강신청 관리 시스템의 규칙을 적용한 후 수강신청에 성공한 인원의 학번을 한 줄에 1개씩 출력한다.
 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;

unordered_set<string> id{};
unordered_map<string, int> id_order{};



int main()
{
    FastIO;
    int K, L;
    cin >> K >> L;
    int order = 0;
    for (int i = 0; i < L; ++i) {
        string tmp; cin >> tmp;
        if(id.find(tmp) == id.end()) {
            id.insert(tmp);
            order++;
            id_order[tmp] = order;
        } else {
            order++;
            id_order[tmp] = order;
        }
    }

    set<pair<int, string>> ans{};
    for (auto const &kv: id_order) {
        ans.insert(pair<int, string>(kv.second, kv.first));
    }

    int i = 0;
    for(pair<int, string> x: ans) {
        i++;
        cout << x.second << endl;
        if(i == K) break;
    }

    return 0;


}