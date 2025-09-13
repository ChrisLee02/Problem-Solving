// OX퀴즈 https://www.acmicpc.net/problem/8958

#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, score=0, temp=0;
    string str;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<str.size(); j++){
            if(str[j]=='O'){
                temp++;
                score+=temp;
            }
            else if(str[j]=='X'){
                temp=0;
            }
        }
        cout<<score<<"\n";
        score=temp=0;
    }
}

/*
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int N, score=0, temp=0;
    char str[80];
    cin>>N;
    int arr[N];
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<(int)strlen(str); j++){
            if(str[j]=='O'){
                temp++;
                score+=temp;
            }
            else if(str[j]=='X'){
                temp=0;
            }
        }
        arr[i]=score;
        score=temp=0;
    }
    for(int i=0; i<N; i++){
        cout<<arr[i]<<"\n";
    }
}
*/