#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;



int main(void)
{
    long long int L, W, H, N, tmp, tmp1,tmp2;
    long long int originvol; // 전체 부피
    long long int nowvol; //이미 채워진 부피 // 큰 박스에 가산점을 줘라
    long long int squarevol; // 정사각형 부피 그때그때 저장
    int boxcount = 0;
    int nowcount;
    cin >> L >> W >> H;
    cin >> N;
    originvol = L*W*H; // 전체 부피는 LWH로 초기화
    nowvol = 0; // 채워진 영역의 부피는 0으로 초기화
    vector<pair<int, int>> squares;
    for(int i = 0; i < N; i++) {
        cin >> tmp1 >> tmp2;
        squares.push_back(make_pair(tmp1,tmp2));
    }
    for(int i = N-1; i >= 0; i--) { //배수 관계 -> 부피 큰 놈부터 채워나가면 됨.
        tmp = pow(2,squares[i].first); //한 변 길이
        squarevol = pow(2,3*squares[i].first); // 2^3i -> 개당 부피
        if( tmp > L || tmp > W || tmp > H) continue; // 삐져나오는 놈들 컷
        else {
            nowcount = int(L/tmp) * int(W/tmp) * int(H/tmp) - int(nowvol/squarevol);
            // cout << "nowcount:" << nowcount << endl;
            // cout << "nowvol:" << nowvol << endl;
            // cout << int(L/짬통) * int(W/짬통) * int(H/짬통)  << " " << int(nowvol/squarevol) <<endl;
            if(nowcount > squares[i].second) { // 박스가 부족한 경우
                 nowcount = squares[i].second;
                 boxcount += nowcount;
            } else {
                 boxcount += nowcount;
            }
            //cout << squarevol << "*" << nowcount << '\n';
            nowvol += squarevol * nowcount;
        }
    }
    if(nowvol==originvol)
    cout << boxcount;
    else
    cout << -1;
    
}
