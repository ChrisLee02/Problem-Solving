/*
오늘은 공주님이 태어난 경사스러운 날이다. 왕은 이 날을 기념하기 위해 늘 꽃이 피어있는 작은 정원을 만들기로 결정했다.

총 N개의 꽃이 있는 데, 꽃은 모두 같은 해에 피어서 같은 해에 진다. 하나의 꽃은 피는 날과 지는 날이 정해져 있다.
 예를 들어, 5월 8일 피어서 6월 13일 지는 꽃은 5월 8일부터 6월 12일까지는 꽃이 피어 있고, 6월 13일을 포함하여 이후로는 꽃을 볼 수 없다는 의미이다.
 (올해는 4, 6, 9, 11월은 30일까지 있고, 1, 3, 5, 7, 8, 10, 12월은 31일까지 있으며, 2월은 28일까지만 있다.)

이러한 N개의 꽃들 중에서 다음의 두 조건을 만족하는 꽃들을 선택하고 싶다.

공주가 가장 좋아하는 계절인 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 한다.
정원이 넓지 않으므로 정원에 심는 꽃들의 수를 가능한 적게 한다.
N개의 꽃들 중에서 위의 두 조건을 만족하는, 즉 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 꽃들을 선택할 때,
 선택한 꽃들의 최소 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 꽃들의 총 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 각 꽃이 피는 날짜와 지는 날짜가 주어진다.
 하나의 날짜는 월과 일을 나타내는 두 숫자로 표현된다. 예를 들어서, 3 8 7 31은 꽃이 3월 8일에 피어서 7월 31일에 진다는 것을 나타낸다.

출력
첫째 줄에 선택한 꽃들의 최소 개수를 출력한다. 만약 두 조건을 만족하는 꽃들을 선택할 수 없다면 0을 출력한다.*/

// 1.

#include <bits/stdc++.h>

#define Pair pair<int,int>
#define Flower pair<Pair, Pair>
#define month first
#define day second
#define start_day first
#define end_day second

using namespace std;

int end_days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Pair date_plus_one_day(Pair &date) {
    if (date.day == end_days[date.month]) {
        return Pair(date.first + 1, 1);
    } else {
        return Pair(date.first, date.second + 1);
    }
}

bool compare_date(Pair a, Pair b) { //a가 b의 앞에 와야 할 때만 true. a<b인지를 반환
    if (a.month == b.month) return a.day < b.day;
    return a.month < b.month;
} // sort의 경우 리턴이 false면 스왑한다.



bool compare_flowers(Flower a, Flower b) {
    if (a.end_day == b.end_day) {
        return compare_date(a.start_day, b.start_day); // 시작일은 빠를수록 앞으로
    } else return compare_date(b.end_day, a.end_day);
}

vector<Flower > flowers{}; // 얘를 지는 날에 대해 내림차순 정렬.
// 첫 기준일은 3월 1일이다. 시작일이 3월 1일보다 작거나 같은 애들. 중 가장 첫 번째 꽃을 고른다.
// 꽃을 고르면 그 다음 기준일은 그 꽃의 지는 날이 된다.
// 시작일은 기준일보다 작거나 같고, 지는날은 기준일보다 커야한다.
// 루프를 돌다가 지는 날이 기준일보다 작거나 같으면 break
// 고른 꽃의 지는 날이 11월 30일보다 크면 종료한다.
// 다음 꽃을 고를 수 없다면 실패.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int cnt = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp1, tmp2, tmp3, tmp4;
        cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
        if (compare_date(Pair(tmp3, tmp4), Pair(3, 2))) continue; // 끝나는 날이 3월 1일 이하인 꽃은 패쓰.
        flowers.emplace_back(Pair(tmp1, tmp2), Pair(tmp3, tmp4));
    }

    sort(flowers.begin(), flowers.end(), compare_flowers);

    Flower NULL_FLOWER = Flower(Pair(0, 0), Pair(0, 0));
    Flower chosen_flower = NULL_FLOWER;
    Pair ref_date = Pair(3,1);
    for (Flower flower: flowers) {
        if(compare_date(flower.end_day, ref_date) || flower.end_day == ref_date ) break;
        else {
            if(compare_date(flower.start_day, ref_date) || flower.start_day == ref_date ) {
                chosen_flower = flower;
                ref_date = chosen_flower.end_day;
                cnt++;
                break;
            }
            else continue;
        }
    }
    if(chosen_flower == NULL_FLOWER) {
        cout << 0;
        return 0;
    }
    if(compare_date(Pair(11, 30) ,chosen_flower.end_day) ) {
        cout << 1;
        return 0;
    }

    while (true) {
        chosen_flower = NULL_FLOWER;
        for (Flower flower: flowers) {
            if(compare_date(flower.end_day, ref_date) || flower.end_day == ref_date) break;
            else {
                if(compare_date(flower.start_day, ref_date) || flower.start_day == ref_date ) {
                    chosen_flower = flower;
                    ref_date = chosen_flower.end_day;
                    cnt++;
                    break;
                }
                else continue;
            }
        }
        if(chosen_flower == NULL_FLOWER) {
            cout << 0;
            return 0;
        }
        if(compare_date(Pair(11, 30) ,chosen_flower.end_day) ) {
            break;
        }
    }
    cout << cnt;


}
