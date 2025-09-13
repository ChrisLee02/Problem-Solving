/* https://www.acmicpc.net/problem/6549

히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다. 각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다. 예를 들어, 왼쪽 그림은 높이가 2, 1, 4, 5, 1, 3, 3이고 너비가 1인 직사각형으로 이루어진 히스토그램이다.



히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.

입력
입력은 테스트 케이스 여러 개로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000) 그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1,000,000,000)가 주어진다. 이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다. 모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스에 대해서, 히스토그램에서 가장 넓이가 큰 직사각형의 넓이를 출력한다. */
//분할점에 걸쳐서 답이 존재할 수 있다는 점.
//이때는 분할점 기준 왼쪽, 오른쪽을 나눠서 각각의 최적해를 구해준 뒤 분할점에서 출발하여 탐색한 3번째 해와 비교하여
//최종 최적해를 구해준다.
#include <iostream>
#include <utility>
#include <tuple>
using namespace std;


// int mergeRectangle( int* Rec1,  int* Rec2) {
//     return Rec1[0] < Rec2[0] ? make_pair(Rec1[0], Rec1[1]+Rec2[1]) : make_pair(Rec2[0], Rec1[1]+Rec2[1]);
//     //높이는 낮은 쪽으로, 너비는 두 직사각형 너비의 합으로 만들어지는 직사각형을 리턴  
// }

//삽질한거: 이분탐색하는 부분에서 인덱스 실수하는 부분 -> 이거 확실하게 잡아놔야겠음.
// 이분탐색이 들어가는데 메모리 초과/시간초과 뜨면 스택오버플로우 의심해보자
//테스트케이스 여러개 들어가는 경우에는 제발 초깃값 설정좀 해라 씨ㅣㅣㅣ팔진짜

long long hist(long long *heights, long long left, long long right ) {
    //cout<<"dd";
    if(left>right) return 0;
    if(left==right) return heights[left];

    long long mid = (right+left) / 2;
    long long rightSolve = hist(heights, left, mid);
    
    long long leftSolve = hist(heights, mid+1, right);
  
    long long midSolver[2];
    midSolver[0] = heights[mid];
    midSolver[1] = 1;
    long long midSolve = heights[mid];
    long long i = mid - 1;
    long long j = mid + 1;
    while(i>=left && j<=right) {
        if(heights[i]>heights[j]){
            midSolver[0] = midSolver[0]<heights[i] ? midSolver[0] : heights[i];
            midSolver[1]++;
            if(midSolve<midSolver[0]*midSolver[1]) midSolve = midSolver[0]*midSolver[1];
           
            i--;
        } 
        else {
            midSolver[0] = midSolver[0]<heights[j] ? midSolver[0] : heights[j];
            midSolver[1]++;
            if(midSolve<midSolver[0]*midSolver[1]) midSolve = midSolver[0]*midSolver[1];
            
            j++;
        }
    }
    while(i>=left) {
        midSolver[0] = midSolver[0]<heights[i] ? midSolver[0] : heights[i];
        midSolver[1]++;
        if(midSolve<midSolver[0]*midSolver[1]) midSolve = midSolver[0]*midSolver[1];
       
        i--;
    }
    while(j<=right) {
        midSolver[0] = midSolver[0]<heights[j] ? midSolver[0] : heights[j];
        midSolver[1]++;
        if(midSolve<midSolver[0]*midSolver[1]) midSolve = midSolver[0]*midSolver[1];
       
        j++;
    }
    return max(max(midSolve,leftSolve),rightSolve);
}

int main(void)
{
    long long n,tmp;
    long long Max;
    long long breakPoint=-1;
    long long *heights = new long long[100003];
    while(1){
        cin >> n;
        if(n==0) return 0;
        Max = 0;
        breakPoint=-1;
        for(long long i = 0; i<n; i++){
            cin>>heights[i];
            if(heights[i]==0) {
                tmp = hist(heights, breakPoint+1, i-1);
                if(Max<tmp) Max=tmp;
                breakPoint = i;
            }
        }
        //pair<pair<long long, long long>, pair<long long, long long>> division1 = hist(&Max, heights, breakPoint+1, n-1, true);
        if(breakPoint!=n-1)
        tmp = hist(heights,  breakPoint+1, n-1);
        if(Max<tmp) Max=tmp;
        cout << Max << '\n';
    }
}
