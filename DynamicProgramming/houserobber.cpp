class Solution
{
public:
    int recursion(int n, vector<int> &nums, vector<int> &dp)
    {
        if (n == 0)
            return nums[0];
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int include = nums[n] + recursion(n - 2, nums, dp);
        int exclude = 0 + recursion(n - 1, nums, dp);
        return dp[n] = max(include, exclude);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int ans = recursion(n - 1, nums, dp);
        return ans;
    }
};