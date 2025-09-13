// 최댓값 https://www.acmicpc.net/problem/2562

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num, max=0, index;
    for(int i=1; i<10; i++){
        cin>>num;
        if(num>max){
            max=num;
            index=i;
        }
    }
    cout<<max<<"\n"<<index;
}