//카운팅 정렬로 풀어야 하는 문제.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class dot {
    private:
        int x;
        int y;
    public:
        dot(int x, int y) {
            this->x = x;
            this->y = y;
        }
        void print() {
            cout << this->x << " " << this->y << '\n';
        }   
        bool operator < (const dot &b) {
            if(this->y != b.y ) return this->y < b.y;
            else return this->x < b.x;
        }

};




int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, tmp1, tmp2;
    cin >> N;
    vector<dot> dots;
    for(int i = 0; i < N; i++) {
        cin >> tmp1 >> tmp2;
        dots.push_back(dot(tmp1, tmp2));
    }
    sort(dots.begin(),dots.end());
    for(int i = 0; i < N; i++) {
        dots[i].print();
    }
}
