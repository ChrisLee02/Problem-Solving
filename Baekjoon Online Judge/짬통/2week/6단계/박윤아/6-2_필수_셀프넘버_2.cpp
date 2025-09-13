// 셀프 넘버 https://www.acmicpc.net/problem/4673

#include <iostream>
using namespace std;

int self_number(int n){
    int result=n;
    while(n>9){
        result+=n%10;
        n/=10;
    }
    result+=n;
    return result;
}

int main(){
    int arr[10000];
    for(int n=1; n<10000; n++){
        arr[n]=0;
    }
    for(int n=1; n<10000; n++){
        if(self_number(n)<10000) arr[self_number(n)]=1;
    }
    for(int n=1; n<10000; n++){
        if(arr[n]==0) cout<<n<<" ";
    }
}

//0ms 풀이