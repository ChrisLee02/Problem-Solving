#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N, T, index = 0;
    vector<int> nums;
    cin >> N;
    bool isIncreasing;
    int MaxIncrease = 1, MaxDecrease = 1;
    int nowIncrease = 1, nowDecrease = 1;
    for (int i = 0; i < N; i++)
    {
        cin >> T;
        nums.push_back(T);
    }
    // while (nums[index] == nums[index + 1])
    // {
    //     nowIncrease++;
    //     nowDecrease++;
    //     MaxIncrease++;
    //     MaxDecrease++;
    //     index++;
    // }
    // if (nums[index] < nums[index + 1])
    // {
    //     isIncreasing = true;
    //     nowDecrease = 1;
    //     nowIncrease++;
    //     index++;
    //     MaxIncrease = nowIncrease;
    // }
    // else
    // {
    //     isIncreasing = false;
    //     nowDecrease++;
    //     nowIncrease = 1;
    //     index++;
    //     MaxDecrease = nowDecrease;
    // }

    for (int i = index; i < N - 1; i++)
    {
        if (nums[index] < nums[index + 1])
        {
            isIncreasing = true;
            if(nowDecrease>MaxDecrease) MaxDecrease = nowDecrease;
            nowDecrease = 1;
            nowIncrease++;
            index++;
            if(nowIncrease>MaxIncrease) MaxIncrease = nowIncrease;
        }
        else if (nums[index] > nums[index + 1])
        {
            isIncreasing = false;
            if(nowIncrease>MaxIncrease) MaxIncrease = nowIncrease;
            nowDecrease++;
            nowIncrease = 1;
            index++;
            if(nowDecrease>MaxDecrease) MaxDecrease = nowDecrease;
        }
        else
        {
            nowDecrease++;
            nowIncrease++;
            index++;
            if (isIncreasing && nowIncrease > MaxIncrease)
                MaxIncrease = nowIncrease;

            if (!isIncreasing && nowDecrease > MaxDecrease)
                MaxDecrease = nowDecrease;
        }
    }
    if(MaxIncrease>MaxDecrease) cout << MaxIncrease;
    else cout << MaxDecrease;
}