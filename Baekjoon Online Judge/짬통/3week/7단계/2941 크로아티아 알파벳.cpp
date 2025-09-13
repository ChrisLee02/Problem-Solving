/* https://www.acmicpc.net/problem/2941
예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 따라서, 다음과 같이 크로아티아 알파벳을 변경해서 입력했다.
크로아티아 알파벳	변경
č	                c=
ć	                c-
dž	                dz=
đ	                d-
lj	                lj
nj	                nj
š	                s=
ž	                z=
예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, k)로 이루어져 있다. 단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.
dž는 무조건 하나의 알파벳으로 쓰이고, d와 ž가 분리된 것으로 보지 않는다. lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.
입력
첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 '-', '='로만 이루어져 있다.
단어는 크로아티아 알파벳으로 이루어져 있다. 문제 설명의 표에 나와있는 알파벳은 변경된 형태로 입력된다.
출력
입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다. */


//=, -, j에 대해 예외처리 해주면 될 듯.
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string alpha;
    int count = 0;
    cin >> alpha;
    int i = alpha.length() - 1;
    while (i>=0)
    {
        if(alpha[i] != '=' && alpha[i] != '-' && alpha[i] != 'j') { // normal case
            count++;
            i--;
            continue;
        }
        if(alpha[i] == 'j') { // lj, nj case test
            if(i==0) { // 첫번째 칸에 j인 경우 = normal case임
                count++;
                break;
            }
            if (alpha[i-1] == 'l' || alpha[i-1] == 'n') { // lj, nj case
                count++;
                i = i-2;
                continue;
            } else { //normal case
                count++;
                i--;
                continue;
            }
        }
        if(alpha[i] == '=') { // c=, s=.z=. dz=
            if (alpha[i-1] == 'c' || alpha[i-1] == 's') { // c=, s= case
                count++;
                i = i-2;
                continue;
            } 
            else if (alpha[i-1]=='z'){ //z=. dz= case
                if(alpha[i-2]=='d') { //dz= case
                    count++;
                    i = i - 3;
                    continue;
                }
                else { // z= case
                    count++;
                    i = i - 2;
                    continue;
                }
            } 
        }
        if(alpha[i] == '-') { // c- d-
            count++;
            i=i-2;
            continue;
        }
    }
    
    cout << count;
}


