/* https://www.acmicpc.net/problem/6549

히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다. 각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다. 예를 들어, 왼쪽 그림은 높이가 2, 1, 4, 5, 1, 3, 3이고 너비가 1인 직사각형으로 이루어진 히스토그램이다.



히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.

입력
입력은 테스트 케이스 여러 개로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000) 그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1,000,000,000)가 주어진다. 이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다. 모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스에 대해서, 히스토그램에서 가장 넓이가 큰 직사각형의 넓이를 출력한다. */

#include <iostream>
#include <utility>
#include <tuple>
using namespace std;


pair<long long, long long> mergeRectangle( pair<long long, long long> Rec1,  pair<long long, long long> Rec2) {
    if(Rec1.first == 0) {
        return make_pair(Rec2.first,Rec2.second);
    }
    if(Rec2.first == 0) {
        return make_pair(Rec1.first,Rec1.second);
    }
    return Rec1.first < Rec2.first ? make_pair(Rec1.first, Rec1.second+Rec2.second) : make_pair(Rec2.first, Rec1.second+Rec2.second);
    //높이는 낮은 쪽으로, 너비는 두 직사각형 너비의 합으로 만들어지는 직사각형을 리턴  
}

pair<pair<long long, long long>, pair<long long, long long>> hist(long long *Max, long long *heights, long long left, long long right,bool isLeft ){
    
    if(right==left) {
        if(heights[right] > *Max) *Max = heights[right];
        return make_pair(make_pair(heights[right], 1),make_pair(heights[right], 1));
    } 
    long long mid = (right+left) / 2;
    pair<long long, long long> tmp, tmp2;
    pair<pair<long long, long long>, pair<long long, long long>> division1 = hist(Max, heights, left, mid, true); //왼쪽 분할, returnLeft값은 false로
    pair<pair<long long, long long>, pair<long long, long long>> division2 = hist(Max, heights, mid+1, right, false); //오른쪽 분할, returnLeft값이 true
    tmp = mergeRectangle(division1.first, division2.first);
    tmp2 = mergeRectangle(division1.first, division2.second);
    if(tmp.first*tmp.second < tmp2.first*tmp2.second) tmp = tmp2;
    tmp2 = mergeRectangle(division1.second, division2.first);
    if(tmp.first*tmp.second < tmp2.first*tmp2.second) tmp = tmp2;
    tmp2 = mergeRectangle(division1.second, division2.second);
    if(tmp.first*tmp.second < tmp2.first*tmp2.second) tmp = tmp2;
    if(tmp.first*tmp.second > *Max) *Max = tmp.first*tmp.second;
    cout << "";
    if(isLeft) { //왼쪽 분할의 경우
        //이때는 넓이가 가장 큰 merged 사각형을 first로, division1의 오른쪽 끝을 second로 리턴
        //first 케이스: first와 first, first와 second, second와 first, second와 second들 중 최댓값으로
        return make_pair(tmp, division1.second);
    }
    else {
        //이때는 넓이가 가장 merged 사각형을 first로, division2의 왼쪽 끝을 first로 리턴
        return make_pair(tmp, division2.second);
    }
    
}
// 왼쪽 직사각형, 오른쪽 직사각형으로 병합할 수 있음. 이때 각 직사각형의 높이를 보면
//최대 넓이랑, 최대 높이를 둘 다 따져줘야 함.
//최대 넓이인 직사각형과 합칠 때 또는 최대 높이인 직사각형과 합칠 때 최적해가 도출되겠죠? 아닌가,,
//두 직사각형에서, 합친 직사각형과 오른쪽 직사각형의 높이로 만들어지는 직사각형을 리턴
//직사각형 -> 높이, 너비로 표현

int main(void)
{
    long long n;
    long long Max;
    int breakPoint=0;
    while(1){
        cin >> n;
        if(n==0) return 0;
        long long *heights = new long long[n+3];
        Max = 0;
        for(long long i = 0; i<n; i++){
            cin>>heights[i];
            // if(heights[i]==0) {
            //     pair<pair<long long, long long>, pair<long long, long long>> division1 = hist(&Max, heights, breakPoint, i-1, true);
            //     breakPoint = i;
            // }
        }
        //pair<pair<long long, long long>, pair<long long, long long>> division1 = hist(&Max, heights, breakPoint+1, n-1, true);
        pair<pair<long long, long long>, pair<long long, long long>> division1 = hist(&Max, heights, 0, n-1, true);
        cout << Max << '\n';
    }
    
}
