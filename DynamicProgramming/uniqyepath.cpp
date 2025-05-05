class Solution
{
public:
    void recursion(int row, int col, int &count, int m, int n)
    {
        if (row == m - 1 && col == n - 1)
        {
            count++;
            return;
        }
        if (row == m || col == n)
            return;
        recursion(row, col + 1, count, m, n);
        recursion(row + 1, col, count, m, n);
    }
    int uniquePaths(int m, int n)
    {
        int count = 0;
        recursion(0, 0, count, m, n);
        return count;
    }
};
// time limti  will exceed as the each index of  2 d array will be anle to go right in n-1 and down=m-1,
// so the total of the will be m+n-2; and this is for one index and for all index it will bbe 2^(n+m);
// thiis is the top down method for this
class Solution
{
public:
    int recursion(int row, int col, vector<vector<int>> &dp)
    {
        if (row == 0 && col == 0)
            return 1;
        if (row == -1 || col == -1)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        int top = recursion(row - 1, col, dp);
        int left = recursion(row, col - 1, dp);
        return dp[row][col] = top + left;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recursion(m - 1, n - 1, dp);
    }
};