//숫자의 개수 https://www.acmicpc.net/problem/2577

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int A, B, C, num;
    vector<int> arr(10);
    cin>>A>>B>>C;
    num = A*B*C;

    while(num>9){
        arr[num%10]++;
        num = num/10;
    }
    arr[num]++;
    for(int i=0; i<10; i++){
        cout<<arr[i]<<"\n";
    }
}
