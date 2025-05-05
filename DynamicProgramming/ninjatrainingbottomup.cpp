int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int days = points.size();
    int activity = 3;
    vector<vector<int>> dp(n, vector<int>(3, -1));

    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                dp[i][j] = points[i][j] + max(dp[i - 1][j + 1], dp[i - 1][j + 2]);
            }
            else if (j == 1)
            {
                dp[i][j] = points[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j + 1]);
            }
            else
                dp[i][j] = points[i][j] + max(dp[i - 1][j - 2], dp[i - 1][j - 1]);

            if (i == n - 1)
            {
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}