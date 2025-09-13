/*

 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;

int N, Q;
set<int> spots{};


int main()
{
    FastIO;
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp;
        if(tmp == 1) spots.insert(i);
    }

    int location = 0;

    for (int i = 0; i < Q; ++i) {
        int command; cin >> command;
        if(command == 1) {
            int I; cin >> I;
            if(spots.find(I-1) == spots.end()) {
                spots.insert(I-1);
            } else {
                spots.erase(I-1);
            }

        } else if(command == 2) {
            int x; cin >> x;
            location = (location + x % N) % N;
        } else if(command == 3) {
            if(spots.empty()) cout << -1 << endl;
            else {
                auto spot_location = spots.lower_bound(location);
                if(spot_location==spots.end()) {
                    cout << N + *spots.begin() - location << endl;
                } else {
                    cout << *spot_location - location << endl;
                }
            }

        }
    }


}