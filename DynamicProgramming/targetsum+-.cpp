class Solution
{
public:
    int n, total;
    vector<vector<int>> dp;

    int recursion(int index, int sum, vector<int> &nums, int target)
    {
        // base case
        if (index == n)
        {
            return (sum == target) ? 1 : 0;
        }

        // shift sum by offset
        int offsetSum = sum + total;
        if (dp[index][offsetSum] != -1)
            return dp[index][offsetSum];

        // choices: add or subtract current number
        int add = recursion(index + 1, sum + nums[index], nums, target);
        int subtract = recursion(index + 1, sum - nums[index], nums, target);

        return dp[index][offsetSum] = add + subtract;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        n = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);

        // dp[index][sum+total] → -1 initially
        dp.assign(n, vector<int>(2 * total + 1, -1));

        return recursion(0, 0, nums, target);
    }
};
