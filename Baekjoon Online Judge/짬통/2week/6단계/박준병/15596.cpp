#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int> &a){

  int result = 0;
  for (size_t  i = 0; i < a.size(); i++){
    result += a[i];
  }

  return result;



}
/*
int main(){

  int n;
  vector <int> a;
  cin >> n;
  for (int i = 0; i<n; i++){
    int x;
    cin >> x;
    a.push_back(x);
  }

  cout << sum(a) << endl;

}
*/
// 이문제 main 필요없음 