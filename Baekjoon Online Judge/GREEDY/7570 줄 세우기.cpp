/*
입력
입력은 2 개의 줄로 이루어져 있다. 첫 줄에는 어린이 수를 나타내는 정수가 주어진다. 둘째 줄에는 처음에 줄서있는 어린이들의 번호가 차례대로 주어진다.
 주어진 번호들 사이에는 공백이 하나씩 들어있다. 단, 어린이 수는 1이상 1,000,000이하의 정수로 제한되고, 어린이 수가 N이면 어린이들의 번호는 1부터 N까지의 정수이다.

출력
입력에서 주어진 어린이들의 줄에 대해 번호순서대로 줄을 세우기 위해 제일 앞이나 제일 뒤로 보내는 어린이 수의 최솟값을 출력해야 한다.
 */



#include <bits/stdc++.h>

using namespace std;

int numTOsec[1000001];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> kids{};
    for (int i = 1; i <= N; ++i) {
        int tmp;
        cin >> tmp;
        kids.push_back(tmp);
        numTOsec[tmp] = i;
    }
   /* for (int i = 1; i <=N; ++i) {
        cout << numTOsec[i] << " ";
    }
    cout <<endl;*/
    int Max = 0;
    for (int i = 1; i <= N; i++) {
        int prev = numTOsec[i];
        int len = 1;
        while(true) {
            int next = numTOsec[i+1];

            if(prev > next) {
                break;
            }
            prev = next;
            i++;
            len++;
        }
        Max = max(Max, len);
    }
    cout << N - Max;


}
