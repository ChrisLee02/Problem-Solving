/* https://www.acmicpc.net/problem/1654
집에서 시간을 보내던 오영식은 박성원의 부름을 받고 급히 달려왔다. 박성원이 캠프 때 쓸 N개의 랜선을 만들어야 하는데 너무 바빠서 영식이에게 도움을 청했다.

이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다. 박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다. 예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm는 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)

편의를 위해 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정하며, 기존의 K개의 랜선으로 N개의 랜선을 만들 수 없는 경우는 없다고 가정하자. 그리고 자를 때는 항상 센티미터 단위로 정수길이만큼 자른다고 가정하자. N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다. 이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다.
K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다. 그리고 항상 K ≦ N 이다. 
 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 랜선의 길이는 2^31-1보다 작거나 같은 자연수이다.

출력
첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다. */

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    long long N,K, i,tmp, left, right, mid;
    long long idealSol = 0;  //랜선 길이를 합친 다음 나누는 경우 -> 이상적인 경우의 최적해이자 문제 상황에서의 해의 상한선이 됨.
    //수가 너무 큼,, 이분 탐색을 써볼까?
    long long realSol; //문제 상황에서의 해
    vector<int> lines;
    cin >> K >> N;
    for (int i = 0; i < K; i++)
    {
        cin >> tmp;
        lines.push_back(tmp);
    }
    left = 1;
    right = 2147483647;
    while(left<=right) { 
        //while문으로 짤 때의 이분 탐색
        //left>right일 때 종료조건임. 재귀에서는 if문으로 판별 후 -1을 리턴했었지?
        //최적해를 갱신하는 로직은 메모이제이션을 쓰는게 가장 깔끔해보임.
        //저장 후 mid + 1 ~ right를 탐색하는 방식이 맞았다.
        tmp = 0;
        mid = (left+right) / 2;
        for (int j = 0; j < K; j++)
        {
           tmp += int(lines[j]/mid);
        }
        if(tmp>=N) { // 탐색 값을 큰 쪽으로 좁혀야 함. 
            realSol = mid;
            left = mid+1;
        }
        else { // 탐색 값을 작은 쪽으로 좁혀야 함
            right = mid-1;
        }

    }
    cout << realSol;
}