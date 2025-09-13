/*
상근이는 발렌타인 데이를 기념해 여자친구에게 노란 장미 N개를 선물하려고 한다. 상근이네 집 근처에 꽃집의 수는 두 개이다.
 두 꽃 집은 발렌타인 대이를 대비해 많은 꽃을 준비했기 때문에, 꽃이 부족한 일은 없다. 하지만, 두 곳 모두 장미를 다발로 묶어서 판다.

첫 번째 꽃집은 장미 A개를 B원에 팔고, 두 번째 꽃집은 C개를 D원에 판다. A, B, C, D는 모두 양의 정수이다.
 만약, 장미 N개를 보다 많이 구매하는 것이 정확하게 N개를 구매하는 것 보다 가격이 저렴하면, N개 보다 많이 구매한 다음 남은 장미는 꽃집 점원에게 줄 것이다.

상근이가 장미를 적어도 N개 구매하는데 필요한 최소 금액을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N, A, B, C, D가 주어진다. N은 10^15를 넘지 않으며, A, B, C, D는 10^5를 넘지 않는다.

출력
첫째 줄에 장미를 적어도 N개 사는데 필요한 돈의 최솟값을 출력한다. 정답은 항상 10^18을 넘지 않는다.
 */


/*
체크해볼 예시: 18 6 4 8 5
 */

#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

long long GCD(int a, int b) {
    if(a<b) return GCD(b,a);

    if(b == 0) return a;
    return GCD(b, a%b);
}

long long LCM(int a, int b) {
    return a*(b/GCD(a,b));
}


int main() {
    long long N;
    int A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    if (B*C<A*D) { // A-B조합이 더 가성비 ㅈ같은 묶음이 되도록.
        swap(&A, &C);
        swap(&B, &D);
    }
    long long lcm = LCM(A,C);
    long long count_bundle_C = N%C == 0 ? N/C : N/C + 1;
    long long ans = count_bundle_C * D;
    for (long long i = 1; i < lcm/A; ++i) {
        if(N-A*i>0) count_bundle_C = (N-A*i)%C == 0 ? (N-A*i)/C : (N-A*i)/C + 1;
        else count_bundle_C = 0;
        if(ans > i*B + count_bundle_C*D) {
            ans = i*B + count_bundle_C*D;
        }
    }
    cout << ans;

}