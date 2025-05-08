class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == 0 && j == 0)
                    continue;

                int top = (i - 1 < 0) ? INT_MAX : dp[i - 1][j];
                int left = (j - 1 < 0) ? INT_MAX : dp[i][j - 1];

                dp[i][j] = grid[i][j] + min(top, left);
            }
        }
        return dp[row - 1][col - 1];
    }
};