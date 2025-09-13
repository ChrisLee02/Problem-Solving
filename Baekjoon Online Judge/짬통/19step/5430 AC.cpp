/* https://www.acmicpc.net/problem/5430
선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.
함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.
함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 수를 버리는 함수이다.
배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.
각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)
다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)
전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.

출력
각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 출력한다.
 */

#include <iostream>
#include <vector>
#include <string>
#include <deque>


using namespace std;
//deque를 이용해서 실제로 뒤집는게 아니라, bool reversed의 상태를 이용하는 방식을 택해야할듯
void print_vector(deque<int> array, bool isReversed) {
    if(array.size()==0) {
        cout<<"[]"<<'\n';
        return;
    }
    cout << '[';
    int i;
    if(isReversed) {
        for(i=array.size()-1; i>=1; i--) {
            cout << array[i] << ",";
        }
    }
    else {
        for(i=0;i<array.size()-1;i++) {
            cout << array[i] << ",";
        }
    }
    cout<< array[i] << ']'<<'\n';
    
}

void parsing(deque<int> &array, string array_in_string, int N) {
    int pos1, pos2,tmp;
    if(N==0) {
        return;
    }
    if(N==1) {
        pos1 = array_in_string.length()-1;
        tmp = stoi(array_in_string.substr(1,pos1-1));
        array.push_back(tmp);
    }
    else {
        pos1 = 0;
        pos2 = array_in_string.find(',', pos1+1);
        tmp = stoi(array_in_string.substr(pos1+1,pos2-pos1-1));
        array.push_back(tmp);
        for(int i = 0; i<N-2; i++) {
            pos1 = pos2;
            pos2 = array_in_string.find(',', pos1+1);
            tmp = stoi(array_in_string.substr(pos1+1,pos2-pos1-1));
            array.push_back(tmp);
        }
        pos1 = pos2;
        pos2 = array_in_string.length()-1;
        int tmp = stoi(array_in_string.substr(pos1+1,pos2-pos1-1));
        array.push_back(tmp);
    }
}


int main(void)
{
    int T, N, P;
    string order, array_in_string;
    bool isReversed = false;
    bool error = false;
    deque<int> array;
    cin >> T;
    for(int i = 0; i<T;i++) {
        isReversed = false;
        error = false;
        cin >> order;
        cin >> N;
        cin >> array_in_string; 
        parsing(array, array_in_string, N);
        // for(int j=0;j<array.size();j++) {
        // cout << array[j] << " ";
        // }   
        //cout<<endl;
        for(int j = 0; j<order.length(); j++) {
            if(error) break;
            //cout << order[j] << endl;
            switch (order[j])
            {
            case 'R':
                isReversed = !isReversed;
                break;
            case 'D':
                if(array.empty()) {
                    cout << "error"<<'\n';
                    error = true;
                    break;
                }
                if(isReversed) {
                    array.pop_back();
                }
                else {
                    array.pop_front();
                }
                break;
            }
        }
        //cout<<isReversed<<endl;
        if(!error) print_vector(array, isReversed);
        while(!array.empty()) {
            array.pop_back();
        }
    }   
}

