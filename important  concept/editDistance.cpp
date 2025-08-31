class Solution
{
public:
    int recursion(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if (j == word2.size())
            return word1.size() - i;
        if (i == word1.size())
            return word2.size() - j;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i] == word2[j])
        {
            return recursion(i + 1, j + 1, word1, word2, dp);
        }

        int insert = 1 + recursion(i, j + 1, word1, word2, dp);
        int replace = 1 + recursion(i + 1, j + 1, word1, word2, dp);
        int remove = 1 + recursion(i + 1, j, word1, word2, dp);

        return dp[i][j] = min({insert, replace, remove});
    }
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return recursion(0, 0, word1, word2, dp);
    }
};