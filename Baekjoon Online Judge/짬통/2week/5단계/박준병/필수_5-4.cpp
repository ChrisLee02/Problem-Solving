/*
3052번 나머지 문제
https://www.acmicpc.net/problem/3052
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

  vector<int> v;
  bool status = true;
  int x;
  int cnt = 1;

  // 1. 벡터 container에 요소넣기
  for(int i=0; i<10; i++){
    cin >> x;
    int y = x % 42;
    v.push_back(y);
  }



  // 2. 중복 판단 알고리즘
  
  for(int j = 0; j < 10; j++){

    for (int k=j; k<9; k++){

      if(v[j] == v[k+1]) status = false;

    }
    if(j != 9){
      if (status) cnt++;
    }

    status = true;


  }

  cout << cnt << endl;
}



  
 




