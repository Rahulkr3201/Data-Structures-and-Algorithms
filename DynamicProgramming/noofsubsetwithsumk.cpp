#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int n;
vector<vector<int>> dp;

// count number of subsets from index 'i' with current sum 'sum'
int countWays(int index, int sum, vector<int> &arr, int k)
{
    // if (sum == k) return 1;       // valid subset found
    // if (index == n) return 0;
    if (index == n)
    {
        if (sum == k)
            return 1;
        return 0;
    }

    if (dp[index][sum] != -1)
        return dp[index][sum];

    // Take current element if it doesn't exceed target
    int take = 0;
    if (sum + arr[index] <= k)
        take = countWays(index + 1, sum + arr[index], arr, k);

    // Not take current element
    int notTake = countWays(index + 1, sum, arr, k);

    return dp[index][sum] = (take + notTake) % mod;
}

int findWays(vector<int> &arr, int k)
{
    n = arr.size();
    dp.assign(n + 1, vector<int>(k + 1, -1)); // initialize memo table
    return countWays(0, 0, arr, k);
}

// this handles the zeroes also