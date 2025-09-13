// https://www.acmicpc.net/problem/9012


#include <iostream>
#include <string>

using namespace std;

string VPS(string Parenthesis) {
    int count = 0;
    for(int i = 0; i < Parenthesis.length(); i++){
        if(Parenthesis[i] == '(') count++;
        else count--;
        if(count<0) return "NO";
    }
    if(count>0) return "NO";
    else return "YES";
}

int main(void){
    int N;
    cin >> N;
    string Parenthesis;
    for(int i = 0; i<N; i++){
       cin >> Parenthesis;
        cout << VPS(Parenthesis) << '\n';
    }
}