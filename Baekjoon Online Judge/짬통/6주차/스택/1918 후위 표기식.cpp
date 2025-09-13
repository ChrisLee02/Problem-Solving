/* 첫째 줄에 중위 표기식이 주어진다. 단 이 수식의 피연산자는 알파벳 대문자로 이루어지며 수식에서 한 번씩만 등장한다. 그리고 -A+B와 같이 -가 가장 앞에 오거나 AB와 같이 *가 생략되는 등의 수식은 주어지지 않는다. 표기식은 알파벳 대문자와 +, -, *, /, (, )로만 이루어져 있으며, 길이는 100을 넘지 않는다. 

출력
첫째 줄에 후위 표기식으로 바뀐 식을 출력하시오 */

#include <iostream>
#include <stack>

using namespace std;
//연산자들을 스택에 집어넣어두고, 비우는 조건이 충족되면 싸그리 비워버리면 됨
//스택을 비우는 조건은 괄호가 닫히거나, */에서 +-로 전환되는 순간에, 또는 끝에 도달했을 때
// 괄호 닫힘 -> 계산을 갈무리하라는 뜻. 괄호가 뒤에 있다면 어차피 뒤 > 앞 순서라서 다 비워도 무방하고, 앞에 있다면 앞부분만 처리되니까 무방함.
//곱셈, 나눗셈은 괄호가 내장되어있는걸로 생각할 수 있음. 만약 +가 뒤에 따라붙으면 괄호처리하는 의미에서 비우고 +-를 담아야함.
//top이 열린괄호면, +, -는 바로 처리해준다.(우선순위에 따라 괄호로 묶는데, +, -는 앞에 있는 놈이 우선순위가 높은걸로 치는듯)
// 즉, A+B+C는 (A+B)+C이므로 AB+C+로 표기해야됨.(ABC++이 아님.)

//위에 다 개소리임
//스택을 비우는 조건은 '괄호가 닫히는 것'으로 환원 가능, 명시적인 괄호가 닫히거나, 앞부분에 식이 쭉 전개되다가 뒤에 +가 붙으면 괄호가 닫히는 것으로 본다.
//곱셈은 곱셈,나눗셈끼리 붙어있는 국소적인 부분에서 앞 -> 뒤 순서로 2짝씩 괄호를 묶을 수 있음.


//핵심: +, - 바로 앞의 묶음은 하나의 괄호로 묶인 식 취급이 가능함. 
// *, /이 얘네끼리 이웃하면 


void empty_stack(stack<char> &Operators) {
    while(Operators.top()!='(') { // 텅 비거나, 아니면 top이 열린괄호일때 탈출
        cout << Operators.top();
        Operators.pop();
    }
}

int main(void)
{
    string input;
    cin >> input;
    stack<char> Parenthesis;
    stack<char> Operators;
    Operators.push('(');
    for(int i = 0; i<input.length();i++) {
        if(input[i] <= 'Z' && input[i]>='A') { // 알파벳: 그냥 출력해
            cout<<input[i];
            continue;
        }
        if(input[i] == '-' || input[i]=='+') { // 덧셈이나 뺄셈 -> 바로 앞에서 괄호가 ()+ 요론 식으로 있다고 볼 수 있음.
                                                //따라서 앞에 열린괄호가 아니면 바로 출력부터 때리기
            if(Operators.top()!='(') {
                empty_stack(Operators);
                Operators.push(input[i]);
            }
            else{
                Operators.push(input[i]);
            }            
            continue;
        }
        if(input[i] == '*' || input[i]=='/') { //A*B*C => (A*B)*C이므로 곱하기와 나누기가 연달아 나오면 바로 앞의 곱셈은 빼준다.
            if(Operators.top()=='*'||Operators.top()=='/') {
                cout<<Operators.top();
                Operators.pop();
                Operators.push(input[i]);
            }
            else{
                Operators.push(input[i]);
            }
            
            continue;
        }
        if(input[i] == '(') {
            Operators.push('(');
            continue;
        }   
        if(input[i] == ')') {
            empty_stack(Operators);//다 비우면 안 될듯.. 여기서 문제다 -> empty_stack의 break 조건을 수정하자
            Operators.pop();
            continue;
        }   
    }
    empty_stack(Operators);
}