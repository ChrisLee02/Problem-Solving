/* https://www.acmicpc.net/problem/1725

히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다. 각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다. 예를 들어, 왼쪽 그림은 높이가 2, 1, 4, 5, 1, 3, 3이고 너비가 1인 직사각형으로 이루어진 히스토그램이다.



히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.

입력
첫 행에는 N (1 ≤ N ≤ 100,000) 이 주어진다. N은 히스토그램의 가로 칸의 수이다. 다음 N 행에 걸쳐 각 칸의 높이가 왼쪽에서부터 차례대로 주어진다. 각 칸의 높이는 1,000,000,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 가장 큰 직사각형의 넓이를 출력한다. 이 값은 20억을 넘지 않는다. */

#include <iostream>
#include <stack>
#include <utility>
using namespace std;
//스택에 높이, 번째를 넣고
//높이가 오름차순(등호 허용)을 유지하도록 push, pop한다.
//오름차순이 깨지는 순간 pop을 해가면서 넓이를 갱신
//시각적으로 본다면, 오름차순이 깨지는 순간 넓이를 모두 갱신하고,
//갱신한 후에는 사각형의 윗부분을 싸그리 깎아내는 거라고 볼 수 있음
int main(void)
{
    long long N, tmp,width,area, top, bottom;
    long long endPos;
    long long Max = 0;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    stack<pair<long long,long long>> Heights;
    pair<long long, long long> topHeight, bottomHeight;
    
    cin >> N;
    for(int i = 0; i<N;) {
        cin >> tmp;
        if(Heights.empty()){
            Heights.push(make_pair(tmp,0)); //초기화 된 후라면 이거 위치를 0으로 잡아줘야됨.
            //ex) 2,2,2,3,1인 상황이면, 1이전 스택이 다 비어버림. 이때는 1,0을 하나 잡아줘야 그 이후에 다시 스택을 비울 때 정상작동함
            i++;
            continue;
        }
        if(Heights.top().first <= tmp){
            Heights.push(make_pair(tmp,i)); //높이, 번째
            i++;
            continue;
        }
        if(Heights.top().first > tmp) {
            endPos=Heights.top().second;
            while(!Heights.empty() && Heights.top().first > tmp) {
                area = Heights.top().first*(endPos-Heights.top().second+1);
                //cout<<endl  << Heights.top().first << " " << Heights.top().second << " " << area << endl<<endl;
                if(area>Max) Max = area;
                Heights.pop();
            }
            if (Heights.empty()) //이쪽의 if-else가 깎아내는 부분에 해당함. 만약 텅 비었다면? 0번째가 처음이 됨.
            //따라서 0번째와 i번째를 각각 짬통(입력 높이)로 만들어주면 된다.
            {
                Heights.push(make_pair(tmp, 0)); //초기화 된 후라면 이거 위치를 0으로 잡아줘야됨.
                                                 // ex) 2,2,2,3,1인 상황이면, 1이전 스택이 다 비어버림. 이때는 1,0을 하나 잡아줘야 그 이후에 다시 스택을 비울 때 정상작동함
                Heights.push(make_pair(tmp, i));
                i++;
                continue;
            }
            
            else // 텅 빈게 아니면, 입력 높이보다 처음으로 작아지는 그 위치에 1을 더한게 깎인 사각형의 오른쪽 끝이 됨.
            //top.second+1와 i를 tmp로 만들어준다.
            {
                Heights.push(make_pair(tmp, Heights.top().second+1)); //높이, 번째
                Heights.push(make_pair(tmp, i));
                i++;
                continue;
            }
        }
    }
    //cout<<Heights.top().first;
    if(!Heights.empty()) {
        endPos=Heights.top().second;
        while(!Heights.empty()) {
            //cout << "Dd";
            area = Heights.top().first*(endPos-Heights.top().second+1);
            //cout << area<<endl;
            if(area>Max) Max = area;
            Heights.pop();
        }
    }
    cout << Max;
}

