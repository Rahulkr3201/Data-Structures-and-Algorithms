class Solution
{
public:
    int dfs(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        int m = matrix.size();
        int n = matrix[0].size();

        int mylen = 1;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y])
            {
                int totallen = 1 + dfs(nx, ny, matrix, dp);
                mylen = max(mylen, totallen);
            }
        }
        return dp[x][y] = mylen;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dfs(i, j, matrix, dp);
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};