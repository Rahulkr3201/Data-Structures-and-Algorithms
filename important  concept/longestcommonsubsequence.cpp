class Solution
{
public:
    int recursion(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (i == text1.size() || j == text2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j])
        {
            return dp[i][j] = 1 + recursion(i + 1, j + 1, text1, text2, dp);
        }
        else
        {
            return dp[i][j] = max(recursion(i, j + 1, text1, text2, dp), recursion(i + 1, j, text1, text2, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));

        return recursion(0, 0, text1, text2, dp);
    }
};