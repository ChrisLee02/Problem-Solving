#include <bits/stdc++.h>

using namespace std;
//커스텀 bigInt + 연산자 오버로딩으로 해결해야햄
class BigInteger { // 0이상만 다룬다
private:
    vector<int> num;

public:
    BigInteger() {
        num = vector<int>();
    }

    BigInteger(int i) {
        if(i==0) {
            num.push_back(0);
            return;
        }

        while(i>0) {
            num.push_back(i%10);
            i = i/10;
        }
    }


    int size(){
        return num.size();
    }

    void print() {
        for(auto i = num.rbegin(); i!=num.rend(); i++) {
            cout << *i;
        }
        cout<<endl;
    }

    BigInteger operator+(BigInteger &ref)
    {
        int carry = 0;
        BigInteger result = BigInteger();
        if(this->size() < ref.size() ) {
            return ref + *this;
        }

        for (int i = 0; i<ref.size(); i++) {
            int plus = num[i] + ref.num[i] + carry;
            carry = plus/10;
            result.num.push_back(plus % 10);
        }

        for (int i = ref.size(); i < this->size(); i++) {
            int plus = num[i] + carry;
            carry = plus/10;
            result.num.push_back(plus % 10);
        }
        if(carry!=0) {
            result.num.push_back(carry);
        }

        return result;
    }

};

void combination(int M, int N) { // mCn을 구하는 상황
    BigInteger **dp = new BigInteger *[M + 1];
    for (int i = 1; i <= M; i++) {
        dp[i] = new BigInteger[i + 1];
        dp[i][0] = BigInteger(1);
        dp[i][i] = BigInteger(1);
    }
    for (int i = 2; i <= M; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    dp[M][N].print();
}


int main() {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    cout << setprecision(30);
    combination(tmp1, tmp2);
}