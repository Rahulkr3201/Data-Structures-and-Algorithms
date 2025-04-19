#include <bits/stdc++.h>
using namespace std;

int recursion(int n, vector<int> &dp, vector<int> &heights)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int right = recursion(n - 1, dp, heights) + abs(heights[n] - heights[n - 1]);
    int left = INT_MAX;

    if (n > 1)
    {
        left = recursion(n - 2, dp, heights) + abs(heights[n] - heights[n - 2]);
    }

    return dp[n] = min(right, left);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    return recursion(n - 1, dp, heights);
}
