#include <bits/stdc++.h>
using namespace std;
int recursion(int rowindex, int colindex, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (rowindex == points.size())
    {
        return 0;
    }
    if (dp[rowindex][colindex] != -1)
        return dp[rowindex][colindex];

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i == colindex)
            continue;

        int result = points[rowindex][colindex] + recursion(rowindex + 1, i, points, dp);
        maxi = max(maxi, result);
    }
    return dp[rowindex][colindex] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    int ans = 0;

    vector<vector<int>> dp(n, vector<int>(3, -1));
    for (int j = 0; j < 3; j++)
    {
        ans = max(ans, recursion(0, j, points, dp));
    }
    return ans;
}
