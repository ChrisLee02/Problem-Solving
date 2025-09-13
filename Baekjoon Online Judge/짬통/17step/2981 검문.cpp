/* https://www.acmicpc.net/problem/2981
트럭을 타고 이동하던 상근이는 경찰의 검문을 받게 되었다. 경찰은 상근이가 운반하던 화물을 하나하나 모두 확인할 것이기 때문에, 
검문하는데 엄청나게 오랜 시간이 걸린다.

상근이는 시간을 때우기 위해서 수학 게임을 하기로 했다.

먼저 근처에 보이는 숫자 N개를 종이에 적는다. 그 다음, 종이에 적은 수를 M으로 나누었을 때, 나머지가 모두 같게 되는 
M을 모두 찾으려고 한다. M은 1보다 커야 한다.

N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램을 작성하시오.

입력
첫째 줄에 종이에 적은 수의 개수 N이 주어진다. (2 ≤ N ≤ 100)

다음 줄부터 N개 줄에는 종이에 적은 수가 하나씩 주어진다. 이 수는 모두 1보다 크거나 같고, 1,000,000,000보다 
작거나 같은 자연수이다. 같은 수가 두 번 이상 주어지지 않는다.

항상 M이 하나 이상 존재하는 경우만 입력으로 주어진다.

출력
첫째 줄에 가능한 M을 공백으로 구분하여 모두 출력한다. 이때, M은 증가하는 순서이어야 한다. 
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(void) 
{
    long long N, tmp, i,j;
    long long K;
    bool istrue;
    int n = 1;
    cin >> N;
    vector<int> nums;
    vector<int> subs;
    vector<int> answers;
    int remainder[200]; // 나머지는 N개의 요소를 갖는 배열 (N개의 각 숫자를 나눈 나머지가 들어감.)
    for(int j = 0; j < N; j++) {  
        cin >> tmp;
        nums.push_back(tmp);
    }


    // nums를 정렬한 뒤 2부터 시작해서 nums의 가장 작은 수까지 시도
    // 가장 작은 수보다 큰걸로 나눌 때, 그러면 나머지 값들 중 하나는 해당 수로 고정이고
    // 만약 그 다음 작은 수보다 더 큰걸로 나눈다면? 그때는 진짜 같을 수가 없다.
    // 따라서 2~nums[1]까지만 나눠보면 됨. 


    // a = b (mod n)을 찾는다는 것은, abs(a-b) = 0 modn을 찾는다는 거임. 씨발?
    // 그러면 이건 차에 해당하는 값을 정렬을 해서? 가장 작은 ㅅㅋ의 약수들을 딱 가져오면 됨.
    // 그리고 걔네들로 나머지 차들에 대해 수행 -> 모든 차들의 공약수들을 구하는 과정.
    sort(nums.begin(),nums.end(),greater<>());
    for(int j = 0; j < N-1; j++) {  
        subs.push_back(nums[j] - nums[j+1]);
    }
    sort(subs.begin(), subs.end());
    K = subs[0];
    for(int i = 2; i<sqrt(K); i++) {
        if(K%i == 0) {
            answers.push_back(i);
        }
    }
    if( sqrt(K)==int(sqrt(K)) ){
        answers.push_back(int(sqrt(K)));
        for(int i = answers.size()-2; i>=0; i--){
            answers.push_back(K/answers[i]);
        }
    }
    else {
        for(int i = answers.size()-1; i>=0; i--){
            answers.push_back(K/answers[i]);
        }
    }
    answers.push_back(K);
    for(int j = 0; j < answers.size(); j++) {
        istrue = true;
        for(int i = 1; i<subs.size(); i++) {
            if(subs[i] % answers[j] != 0) {
                istrue = false;
                break;
            } 
        }
        if(istrue)
        cout << answers[j] << " ";
    }
}
