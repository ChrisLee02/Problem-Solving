/* https://www.acmicpc.net/problem/14888
N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 
연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.
우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.
예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 주어진 연산자가 덧셈(+) 2개, 뺄셈(-) 1개, 곱셈(×) 1개, 나눗셈(÷) 
1개인 경우에는 총 60가지의 식을 만들 수 있다. 예를 들어, 아래와 같은 식을 만들 수 있다.
1+2+3-4×5÷6
1÷2+3+4-5×6
1+2÷3×4-5+6
1÷2×3-4+5+6
식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 음수를 양수로 나눌 때는
C++14의 기준을 따른다. 즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.
1+2+3-4×5÷6 = 1
1÷2+3+4-5×6 = 12                
1+2÷3×4-5+6 = 5
1÷2×3-4+5+6 = 7
N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.
입력
첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 셋째 줄에는 합이 N-1인 4개의 
정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다. 
출력
첫째 줄에 만들 수 있는 식의 결과의 최댓값을, 둘째 줄에는 최솟값을 출력한다. 연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고, 
10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 또'한, 앞에서부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고
, 10억보다 작거나 같다. */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>


using namespace std;


void initMax(int *Max, vector<int> &Operator, vector<int> &nums) {
    int i,j;
    j=1;
    *Max = nums[0];
    for(int k = 0; k<Operator[0];k++) {
        *Max = *(Max) + nums[j];
        j++;
    }
    for(int k = 0; k<Operator[1];k++) {
        *Max = *(Max) - nums[j];
        j++;
    }
    for(int k = 0; k<Operator[2];k++) {
        *Max = *(Max) * nums[j];
        j++;
    }
    for(int k = 0; k<Operator[3];k++) {
        *Max = *(Max) / nums[j];
        j++;
    }
}
// 두 종류의 연산자만 있을 때 문제가 어떻게 되는가에 대한 고민을 확장하면 답에 도달할 수 있다!
// Special Thanks to ChrisLee
// 예를 들어서, +와 x만 남았다고 했을 때는 +로 앞을 채우고 x를 뒤에 두는게 무조건 맞음.
// 성능 자체는 4C2 = 6개의 if문으로 하는게 좋을 듯한데, 구현은 아래의 내용이 더 보기 좋을듯.
void findMax_BackTracking(int *Max, int N, vector<int> &Operator, vector<int> &nums, stack<int> &NthResult) {
    int tmp = NthResult.top();
    int n = NthResult.size();
    //cout << " ";
    if(n == N) { // N번째 결과(정답후보)에 도달했다면, 최댓값과 비교 후 갱신
        if( NthResult.top() > *Max) *Max = NthResult.top();
       // NthResult.pop();
        return;
    }
    if(NthResult.top() <= *Max && *Max <= 0 && Operator[0] == 0 && Operator[3]==0 ) { 
        // 음수일 때 가지치기 조건: 현재 시점에서 최댓값보다 작고, 최댓값이 0또는 음수이면서 
        // +와 /을 다 사용한 경우 -> 더 나아질 여지가 없음. + - x /
       // NthResult.pop();
        return;
    }
    if(NthResult.top() <= *Max && *Max >= 0 && Operator[0] == 0 && Operator[2]==0 ) { 
        // 음수일 때 가지치기 조건: 현재 시점에서 최댓값보다 작고, 최댓값이 0또는 양수이면서 
        // +와 x를 다 사용한 경우 -> 더 나아질 여지가 없음. + - x /
        //NthResult.pop(); 왜 씨발 이게 작동을 안함? 
        //함수 인자로 스택 전달할 때, . 대신 -> 써야되는건가? 이건 알아봐야할듯.
        return;
    }
    if(Operator[0]>0) {
        tmp = NthResult.top()+nums[n];
     //   cout << 짬통 << " " << NthResult.top() << " " << nums[n] << endl;
        NthResult.push(tmp);
        Operator[0]--;
        findMax_BackTracking(Max, N, Operator, nums, NthResult);
        NthResult.pop();
        n = NthResult.size();
        Operator[0]++;
    }
    if(Operator[1]>0) {
        tmp = NthResult.top()-nums[n];
    //    cout << 짬통 << " " << NthResult.top() << " " << nums[n] << endl;
        NthResult.push(tmp);
        Operator[1]--;
        findMax_BackTracking(Max, N, Operator, nums, NthResult);
        NthResult.pop();
        n = NthResult.size();
        Operator[1]++;
    }
    if(Operator[2]>0) {
        tmp = NthResult.top()*nums[n];
    //    cout << 짬통 << " " << NthResult.top() << " " << nums[n] << endl;
        NthResult.push(tmp);
        Operator[2]--;
        findMax_BackTracking(Max, N, Operator, nums, NthResult);
        NthResult.pop();
        n = NthResult.size();
        Operator[2]++;
    }
    if(Operator[3]>0) {
        tmp = (NthResult.top())/nums[n];
    //    cout << 짬통 << " " << NthResult.top() << " " << nums[n] << endl;
        NthResult.push(tmp);
        Operator[3]--;
        findMax_BackTracking(Max, N, Operator, nums, NthResult);
        NthResult.pop();
        n = NthResult.size();
        Operator[3]++;
    }

}

void findMin_BackTracking(int *Min, int N, vector<int> &Operator, vector<int> &nums, stack<int> &NthResult) {
    int tmp = NthResult.top();
    int n = NthResult.size();
    //cout << " ";
    if(n == N) { // N번째 결과(정답후보)에 도달했다면, 최댓값과 비교 후 갱신
        if( NthResult.top() < *Min) *Min = NthResult.top();
       // NthResult.pop();
        return;
    }
    if(NthResult.top() >= *Min && *Min <= 0 && Operator[1] == 0 && Operator[2]==0 ) { 
        // 음수일 때 가지치기 조건: 현재 시점에서 최솟값보다 작고, 최댓값이 0또는 음수이면서 
        // 앞으로 커질 일만 남은 경우 -> 음수일 경우에는 -와 x가 0인 경우
       // NthResult.pop();
        return;
    }
    if(NthResult.top() >= *Min && *Min >= 0 && Operator[1] == 0 && Operator[3]==0 ) { 
        // 음수일 때 가지치기 조건: 현재 시점에서 최솟값보다 작고, 최댓값이 0또는 음수이면서 
        // 앞으로 커질 일만 남은 경우 -> 양수일 경우에는 -와 /가 0인 경우
        //NthResult.pop(); 왜 씨발 이게 작동을 안함? 
        //함수 인자로 스택 전달할 때, . 대신 -> 써야되는건가? 이건 알아봐야할듯.
        return;
    }
    if(Operator[0]>0) {
        tmp = NthResult.top()+nums[n];
     //   cout << 짬통 << " " << NthResult.top() << " " << nums[n] << endl;
        NthResult.push(tmp);
        Operator[0]--;
        findMin_BackTracking(Min, N, Operator, nums, NthResult);
        NthResult.pop();
        n = NthResult.size();
        Operator[0]++;
    }
    if(Operator[1]>0) {
        tmp = NthResult.top()-nums[n];
    //    cout << 짬통 << " " << NthResult.top() << " " << nums[n] << endl;
        NthResult.push(tmp);
        Operator[1]--;
        findMin_BackTracking(Min, N, Operator, nums, NthResult);
        NthResult.pop();
        n = NthResult.size();
        Operator[1]++;
    }
    if(Operator[2]>0) {
        tmp = NthResult.top()*nums[n];
    //    cout << 짬통 << " " << NthResult.top() << " " << nums[n] << endl;
        NthResult.push(tmp);
        Operator[2]--;
        findMin_BackTracking(Min, N, Operator, nums, NthResult);
        NthResult.pop();
        n = NthResult.size();
        Operator[2]++;
    }
    if(Operator[3]>0) {
        tmp = (NthResult.top())/nums[n];
    //    cout << 짬통 << " " << NthResult.top() << " " << nums[n] << endl;
        NthResult.push(tmp);
        Operator[3]--;
        findMin_BackTracking(Min, N, Operator, nums, NthResult);
        NthResult.pop();
        n = NthResult.size();
        Operator[3]++;
    }

}

int main(void) 
{
    int N, i, j, tmp;
    cin >> N;
    vector<int> nums;
    vector<int> Operator;
    stack<int> NthResult;
    int Max,Min;
    for(i = 0; i<N; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    for(i = 0; i<4; i++) { // +, -, x, /이 각 인덱스에 들어있는걸로 생각
        cin >> tmp;
        Operator.push_back(tmp);
    }
    initMax(&Max, Operator, nums); // 그냥 +-X/순으로 일단 최댓값 초기화
    initMax(&Min, Operator, nums); // 마찬가지로 최솟값도 초기화
    NthResult.push(nums[0]);
    findMax_BackTracking(&Max, N, Operator, nums, NthResult);
    findMin_BackTracking(&Min, N, Operator, nums, NthResult);
    cout << Max << endl << Min;
}
