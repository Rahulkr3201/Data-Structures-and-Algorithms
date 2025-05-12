class Solution
{
public:
    long long recursion(int row, vector<vector<int>> &questions, vector<long long> &dp)
    {
        if (row >= questions.size())
        {
            return 0;
        }
        if (dp[row] != -1)
            return dp[row];
        long long nextrow = row + 1 + questions[row][1];

        long long pick = questions[row][0] + recursion(nextrow, questions, dp);
        long long notpick = recursion(row + 1, questions, dp);

        return dp[row] = max(pick, notpick);
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        int row = questions.size();
        int col = questions[0].size();
        vector<long long> dp(row, -1);
        return recursion(0, questions, dp);
    }
};