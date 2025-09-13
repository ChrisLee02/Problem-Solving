/* https://www.acmicpc.net/problem/9663
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다. */

#include <iostream> 
#include <string>
#include <utility>//pair 포함 헤더
#include <vector>
#include <algorithm>

using namespace std;


class dot {
    private:
        
    public:
        int x;
        int y;
        dot(int x, int y) {
            this->x = x;
            this->y = y;
        }
        void print() {
            cout << this->x << " " << this->y << '\n';
        }   
        bool operator < (const dot &b) {
            if(this->x != b.x ) return this->x < b.x;
            else return this->y < b.y;
        }
        bool isAble(const dot &anotherQueen) {
            if(this->x == anotherQueen.x) return false;
            if(this->y == anotherQueen.y) return false;
            if( (this->x) - (anotherQueen.x) == (this->y) - (anotherQueen.y)) return false;
            if( (this->x) - (anotherQueen.x) == -(this->y) + (anotherQueen.y)) return false;
            return true;
        }
};

vector<pair<int, int>> Queens;
bool *existrow;
bool *existcol;


void NQueen(int N, int *count, int i, int j)
{ // 공간복잡도 문제가 생길지도..
    if (N == Queens.size())
    {
        *count = (*count) + 1;
        return;
    }
    int newi = i+1;
        for (int newj = 1; newj <= N; newj++)
        {
            if(existcol[newj]) continue;
            bool isAble = true;
            
            for (int k = 0; k < Queens.size(); k++)
            {
                // Queens[k].print();
                if(newi == Queens[k].first) isAble = false;
                else if(newj == Queens[k].second)isAble = false;
                else if( newi - Queens[k].first == newj - Queens[k].second ) isAble= false;
                else if( newi - Queens[k].first == - newj + Queens[k].second ) isAble= false;
                else isAble= true;
                if (!isAble)
                {
                    break;
                }
            }
             //cout<<'\n';
            if (isAble)
            {
                Queens.push_back(make_pair(newi,newj));
                existrow[newi] = true;
                existcol[newj] = true;
                NQueen(N, count, newi, newj);
                Queens.pop_back();
                existrow[newi] = false;
                existcol[newj] = false;
            }
            
        }
    
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int N;
    int count = 0;
    cin >> N;
    existcol = new bool[N+1];
    existrow = new bool[N+1];
    fill_n(existcol, N+1, false);
    fill_n(existrow, N+1, false);
    for(int i = 1; i<=N; i++) {
        Queens.push_back(make_pair(1,i));
        existrow[1] = true;
        existcol[i] = true;
        NQueen(N,&count,1,i);
        existrow[1] = false;
        existcol[i] = false;
        Queens.pop_back();
    }
    
    cout << count;
}