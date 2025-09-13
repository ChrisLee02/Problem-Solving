/* https://www.acmicpc.net/problem/4949

세계는 균형이 잘 잡혀있어야 한다. 양과 음, 빛과 어둠 그리고 왼쪽 괄호와 오른쪽 괄호처럼 말이다.

정민이의 임무는 어떤 문자열이 주어졌을 때, 괄호들의 균형이 잘 맞춰져 있는지 판단하는 프로그램을 짜는 것이다.

문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류이고, 문자열이 균형을 이루는 조건은 아래와 같다.

모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
정민이를 도와 문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지를 판단해보자.

입력
하나 또는 여러줄에 걸쳐서 문자열이 주어진다. 각 문자열은 영문 알파벳, 공백, 소괄호("( )") 대괄호("[ ]")등으로 이루어져 있으며,
 길이는 100글자보다 작거나 같다.

입력의 종료조건으로 맨 마지막에 점 하나(".")가 들어온다.
출력
각 줄마다 해당 문자열이 균형을 이루고 있으면 "yes"를, 아니면 "no"를 출력한다.*/

//스택 두개 만들고, 한 쪽이 비었을 때만 다른 한 쪽에 넣거나 빼는 것을 허용 -> 괄호 간 1대1매칭 조건에 해당
//스택이 비었는데 pop을 하거나, 문자열이 끝났는데 스택이 모두 비어있지 않아도 no출력

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,M, tmp;
    string order;
    stack<char> Parentheses;
    while(1) {
        getline(cin,order);
        if(order==".") break;
        else {
            for(int i = 0; i<order.length(); i++) {
                if(order[i]=='[') {
                    Parentheses.push('[');
                }
                if(order[i]=='(') {
                    Parentheses.push('(');
                }

                if(order[i]==']') {
                    if( Parentheses.empty() || Parentheses.top() != '[' ) { // 작은 괄호가 열려있거나, 괄호가 비어있다면
                        Parentheses.push('['); //break문으로 나왔으면 empty가 아니도록 사전처리 해줌
                        break;
                    }
                    else {
                        Parentheses.pop();
                    }
                }
                if(order[i]==')') {
                    if(Parentheses.empty() || Parentheses.top() != '(') { // 큰 괄호가 아직 닫히지 않았다면?
                        Parentheses.push('['); //break문으로 나왔으면 empty가 아니도록 사전처리 해줌
                        break;
                    }
                    else {
                        Parentheses.pop();
                    }
                }
            }
            if(Parentheses.empty()) { //여기서 한 번에 처리해야 맞다. 잘못 닫히는 경우 + 안 닫힌 경우(요걸 놓쳤음.)
                cout << "yes" << '\n';
            } else {
                cout << "no" << '\n';
            }
            while(!Parentheses.empty()){ // 청소
                Parentheses.pop();
            }
        }
    }

}