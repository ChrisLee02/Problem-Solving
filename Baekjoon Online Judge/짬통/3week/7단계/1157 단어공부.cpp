/* https://www.acmicpc.net/problem/1157
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다. */

#include <iostream>
#include <string>

using namespace std;


// 정렬 후 나뉘는 부분마다 세서 최댓값을 반환하는 방식.



int main(void)
{
    string alpha;
    int tmp;
    int max = 0;
    int max_index;
    int count[26] = {0, }; // 또는 fill_n(count, 26, 0);
    cin >> alpha;
    for(int i = 0; i<alpha.length(); i++) {
        if(alpha[i] >= 'a' ) {
            tmp = alpha[i] - 'a';
            count[tmp]++;
        } else {
            tmp = alpha[i] - 'A';
            count[tmp]++;
        }
    }

    for(int i = 0; i<26; i++) {
        if (max<count[i])
        {
            max = count[i];
            max_index = i;
        }
    }

    for(int i = 0; i<26; i++) {
        if (max==count[i] && max_index!=i)
        {
            cout << '?';
            return 0;
        }
    }

    cout << char(max_index+'A');

}