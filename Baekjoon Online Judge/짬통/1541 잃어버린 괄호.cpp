//https://www.acmicpc.net/problem/1541
/* 세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다. */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//-가 하나라도 나오는 순간, 그 뒷부분은 전부 -로 바꿀 수 있음 그리고 그때 최소가 된다
// int strToint(string nums_int_string) { // stoi함수가 있답니다~

// }

int main(void)
{
    string expression;
    vector<int> nums;
    vector<string> nums_in_string;
    queue<char> Operators;
    int sum = 0;
    cin >> expression;
    int pos= 0;
    //int newpos1, newpos2;
    if( expression.find('+') == string::npos && expression.find('-') == string::npos) {
        cout << stoi(expression);
        return 0;
    }
    Operators.push('+');
    while(expression.find('+',pos) != string::npos || expression.find('-',pos) != string::npos ) {
        if( expression.find('+',pos) < expression.find('-',pos)) {
            //cout <<"dd"<<endl;
            Operators.push('+');
            nums.push_back(stoi(expression.substr(pos, expression.find('+',pos)-pos)) );
            pos = expression.find('+',pos) + 1;
        }
        else {
            //cout<<"xx"<<endl;
            Operators.push('-');
            nums.push_back(stoi(expression.substr(pos, expression.find('-',pos)-pos)) );
            pos = expression.find('-',pos) + 1;
        }
    }
    nums.push_back(stoi(expression.substr(pos, expression.length()-pos)));
    for(int i = 0; i<nums.size(); i++) {
        //cout<<nums[i]<<endl;
        if(Operators.front()=='-') {
            sum = sum - nums[i];
        }
        else {
            sum = sum+nums[i];
            Operators.pop();
        }
    }
    cout << sum;
}
