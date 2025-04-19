class Solution
{
public:
    int recursion(int n, vector<int> &dp)
    {
        if (n <= 1)
        {
            return n;
        }
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = recursion(n - 1, dp) + recursion(n - 2, dp);
    }

    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        int ans = recursion(n, dp);
    }
};
// space comp= o(n)stack space +0(n)dp array