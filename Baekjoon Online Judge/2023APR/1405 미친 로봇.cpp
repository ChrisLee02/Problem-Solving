#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


class Map {
    private:
        int map[30][30];

    public:
        double E, W, S, N;
        Map(double A, double B, double C, double D) {
            for(int i = 0; i<30; i++) {
                for(int j = 0; j<30; j++) {
                    map[i][j] = 0;
                }
            }
            E = A / 100;
            W = B / 100;
            S = C / 100;
            N = D / 100;

        }
        int getVal(int x, int y) {
            return map[x+14][y+14];
        }
        void setVal(int x, int y, int val) {
            map[x+14][y+14] = val;
        }
};

double recursion(Map map, int count, int n, int x, int y) { // count는 시행 직전에 앞 시행횟수로 따짐, 시작 시점에 count = 0으로 간주됨
    if(count == n) return 1;

    map.setVal(x,y,1);
    double result = 0;

    if(map.getVal(x,y+1)==0) result = result + map.N * recursion(map, count + 1, n, x, y+1);
    if(map.getVal(x,y-1)==0) result = result + map.S * recursion(map, count + 1, n, x, y-1);
    if(map.getVal(x+1,y)==0) result = result + map.E * recursion(map, count + 1, n, x+1, y);
    if(map.getVal(x-1,y)==0) result = result + map.W * recursion(map, count + 1, n, x-1, y);

    map.setVal(x,y,0);
    return result;
}

int main()
{
    cout << setprecision(16); // show 16 digits
    int n;
    double A, B, C, D;
    cin >> n >> A >> B >> C >> D;
    Map map = Map(A, B, C, D);

    cout << recursion(map, 0, n, 0,0);

}