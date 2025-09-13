// 최소, 최대 https://www.acmicpc.net/problem/10818

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, num, max=-1000000, min=1000000;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num;
        if(num>max) max=num;
        if(num<min) min=num;
    }
    cout<<min<<" "<<max;
}

