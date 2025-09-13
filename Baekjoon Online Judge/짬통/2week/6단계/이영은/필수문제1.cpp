/*
    정수 N개의 합
    https://www.acmicpc.net/problem/15596
*/

#include <iostream>
#include <vector>

using namespace std;

long long sum(std::vector<int> &a){
    long long ans=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        ans=ans+a[i];
    }
    return ans;
}