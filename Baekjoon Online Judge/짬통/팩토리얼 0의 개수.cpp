#include <iostream>


using namespace std;

int main(void)
{
    int N,tmp;
    int Two = 0;
    int Five = 0;
    cin >> N;

    for(int i = 1;  i<=N; i++) {
        tmp = i;
        while(tmp%2==0) {
            tmp = tmp/2;
            Two++;
        }
        while(tmp%5 == 0) {
            tmp = tmp/5;
            Five++;
        }
    }
    cout<< min(Two,Five);
}