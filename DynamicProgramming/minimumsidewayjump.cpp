class Solution
{
public:
    int solve(int idx, int currLane, vector<int> &obstacles, vector<vector<int>> &dp)
    {
        if (idx == obstacles.size() - 1)
            return 0;
        if (dp[idx][currLane] != -1)
            return dp[idx][currLane];
        if (obstacles[idx + 1] != currLane)
            return solve(idx + 1, currLane, obstacles, dp);
        int mn = 1e9;
        for (int i = 1; i <= 3; i++)
        {
            if (i != currLane && obstacles[idx] != i)
            {
                mn = min(mn, 1 + solve(idx + 1, i, obstacles, dp));
            }
        }
        return dp[idx][currLane] = mn;
    }
    int minSideJumps(vector<int> &obstacles)
    {
        int n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(0, 2, obstacles, dp);
    }
};