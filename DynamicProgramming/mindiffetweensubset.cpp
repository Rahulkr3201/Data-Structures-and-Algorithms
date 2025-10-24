#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> dp;

// Recursion with memoization
bool canMake(int index, int sum, vector<int> &arr)
{
    if (sum == 0)
        return true; // subset sum achieved
    if (index == n)
        return false; // no elements left

    if (dp[index][sum] != -1)
        return dp[index][sum];

    if (arr[index] > sum)
        return dp[index][sum] = canMake(index + 1, sum, arr);

    bool take = canMake(index + 1, sum - arr[index], arr);
    bool notTake = canMake(index + 1, sum, arr);

    return dp[index][sum] = take || notTake;
}

int minSubsetSumDifference(vector<int> &arr, int _n)
{
    n = _n;
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int target = totalSum / 2;

    dp.assign(n, vector<int>(target + 1, -1));

    int bestSubsetSum = 0;
    for (int s = target; s >= 0; s--)
    {
        if (canMake(0, s, arr))
        {
            bestSubsetSum = s;
            break;
        }
    }

    return totalSum - 2 * bestSubsetSum;
}

// here all are no negative means . subset1==totalsum/2;
// means both are equal and subset1==subset2. and to make difference we should decreaset the subset1 to the first less than toatlsum/2
// or increase the subset2 more from totalsum/2. but here i choose to decrease the subset1 to equal to totalsum/2 or first smaller than that