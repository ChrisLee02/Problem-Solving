/* https://www.acmicpc.net/problem/1874
스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다. 
스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 자료가 제일 먼저 나오는 
(LIFO, Last in First out) 특성을 가지고 있다.

1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으  로써, 하나의 수열을 만들 수 있다. 
이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 임의의 수열이 주어졌을 때 
스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 
이를 계산하는 프로그램을 작성하라.

입력
첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다.
물론 같은 정수가 두 번 나오는 일은 없다.

출력
입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. push연산은 +로, pop 연산은 -로 표현하도록 한다. 
불가능한 경우 NO를 출력한다.
 */

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stack>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    stack<int> nums;
    vector<int> seq;
    vector<char> print;
    int N,i,j,tmp;
    cin>>N;
    int lastpushed = 1; // lastpushed 변수를 이용하면 시간복잡도가 n이 될듯?
    //스택의 특성 상, 마지막으로 들어간 값만 기억하면 그 앞 값들은 push에서 고려대상이 아니게 됨.
    for(int i = 1; i<=N; i++) {
        cin>>tmp;
        seq.push_back(tmp);
    }

    for (j = 1; j <= seq[0]; j++)
    {
        nums.push(j);
        print.push_back('+');
    }
    lastpushed = seq[0];
    print.push_back('-');
    nums.pop();
    for( i = 1; i<N; i++) {
        for( j = lastpushed+1; j<=seq[i]; j++) {
            nums.push(j);
            print.push_back('+');
        }
        lastpushed=j-1;
        if(nums.top() == seq[i]){
            print.push_back('-');
            nums.pop();
        } else {
            cout<<"NO";
            return 0;
        }
    }
    for(int i = 0; i<2*N; i++) {
        cout << print[i] << '\n';
    }

}