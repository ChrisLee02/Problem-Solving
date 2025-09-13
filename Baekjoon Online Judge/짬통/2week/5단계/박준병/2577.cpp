#include <iostream>
#include <vector>

using namespace std;


int main(){
  int a,b,c;
  vector <int> v;

  cin >> a >> b >> c;
  int result = a * b * c;

  // 1. 각 자릿수를 Vector에 넣기

  while(result){
    int tmp = result % 10;
    v.push_back(tmp);
    result /= 10;
  }

  // 2. 0~9 쓰인 횟수 계산 

  for(int i=0; i<10 ; i++){
    int cnt = 0;
    
    for(int j = 0 ; j<v.size(); j++){

      if(i == v[j]) cnt ++;

    }

    cout << cnt << endl;
  }


}