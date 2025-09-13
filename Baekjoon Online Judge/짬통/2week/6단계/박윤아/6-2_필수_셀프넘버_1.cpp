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
bool find_gen(int n){
    for(int i=1; i<n; i++){
        if(self_number(i)==n) return 1;
    }
    return 0;
}
int main(){
    for(int n=1; n<10000; n++){
        if(!find_gen(n)) cout<<n<<"\n";
    }
}

// 188ms 풀이