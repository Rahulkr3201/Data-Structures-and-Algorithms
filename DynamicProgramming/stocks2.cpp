class Solution
{
public:
    int recursion(int index, bool buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        if (buy)
        {
            dp[index][buy] = max(
                prices[index] + recursion(index + 1, false, prices, dp),
                recursion(index + 1, true, prices, dp));
        }
        else
        {
            dp[index][buy] = max(
                -prices[index] + recursion(index + 1, true, prices, dp),
                recursion(index + 1, false, prices, dp));
        }
        return dp[index][buy];
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return recursion(0, false, prices, dp);
    }
};
