class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        if (row == 1 && col == 1)
            return matrix[0][0];
        vector<vector<int>> dp(row, vector<int>(col));
        for (int i = 0; i < col; i++)
        {
            dp[0][i] = matrix[0][i];
        }
        int ans = INT_MAX;
        for (int i = 1; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int topleft = (j - 1 < 0) ? INT_MAX : dp[i - 1][j - 1];
                int topup = dp[i - 1][j];
                int topright = (j + 1 == col) ? INT_MAX : dp[i - 1][j + 1];
                dp[i][j] = matrix[i][j] + min(topleft, min(topup, topright));

                if (i == row - 1)
                {
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
