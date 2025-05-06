// tabular bottom up
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(column));
        if (obstacleGrid[0][0] == 1)
            dp[0][0] = 0;
        else
            dp[0][0] = 1;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (i == 0 && j == 0)
                    continue;

                int top = (i - 1 < 0) ? 0 : dp[i - 1][j];
                int left = (j - 1 < 0) ? 0 : dp[i][j - 1];
                dp[i][j] = top + left;
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
            }
        }
        return dp[row - 1][column - 1];
    }
};