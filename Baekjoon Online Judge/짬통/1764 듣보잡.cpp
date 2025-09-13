#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int N,M;
    string tmp;
    int count = 0;
    vector<string> listened;
    vector<string> watched;
    vector<string> listenedNwatched;
    cin >> N >> M;
    for(int i = 0; i<N;i++) {
        cin >> tmp;
        listened.push_back(tmp);
    }
    for(int i = 0; i<M;i++) {
        cin >> tmp;
        watched.push_back(tmp);
    }
    sort(listened.begin(), listened.end());
    sort(watched.begin(), watched.end());
    for(int i = 0; i< N; i++) {
        if(binary_search(watched.begin(), watched.end(), listened[i])) {
            count++;
            listenedNwatched.push_back(listened[i]);
        }
    }
    cout << count<<endl;
    for(int i = 0; i<listenedNwatched.size();i++) {
        cout << listenedNwatched[i] << '\n';
    }
}
