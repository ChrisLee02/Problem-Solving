/*
9498 - 시험 성적
https://www.acmicpc.net/problem/9498
*/

#include <iostream>
using namespace std;

int main(){
    int score; char grade;
    cin>> score;

    if(90<=score) grade='A';
    else if(80<=score) grade='B';
    else if(70<=score) grade='C';
    else if(60<=score) grade='D';
    else grade='F';

    cout<< grade <<endl;
}

