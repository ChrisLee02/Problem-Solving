// 평균은 넘겠지 https://www.acmicpc.net/problem/4344

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int C, N;
    cin>>C;
    cout<<fixed;
    cout.precision(3);

    for(int i=0; i<C; i++){
        int sum=0, cnt=0;
        double average;
        cin>>N;
        vector<int> score(N);
        for(int j=0; j<N; j++){
            cin>>score[j];
            sum+=score[j];
        }
        average=(double)sum/N;
        for(int j=0; j<N; j++){
            if(score[j]>average) cnt++;
        }
        cout<<(double)cnt/N*100<<"%\n";
    }
}