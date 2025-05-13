#include <bits/stdc++.h>

bool recursion(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (index == 0)
        return target == arr[0];
    if (dp[index][target] != -1)
        return dp[index][target];

    bool take = false;
    if (target >= arr[index])
    {
        take = recursion(index - 1, target - arr[index], arr, dp);
    }

    bool nottake = recursion(index - 1, target, arr, dp);

    return dp[index][target] = take || nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return recursion(n - 1, k, arr, dp);
}