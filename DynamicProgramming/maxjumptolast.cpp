class Solution
{
public:
    int rec(int index, vector<int> &nums, int target, vector<int> &dp)
    {
        if (index == nums.size() - 1)
        {
            return 0;
        }
        if (dp[index] != -2)
            return dp[index];
        int maxJump = -1;
        for (int i = index + 1; i < nums.size(); i++)
        {
            if (-target <= nums[i] - nums[index] && nums[i] - nums[index] <= target)
            {
                int result = rec(i, nums, target, dp);
                if (result != -1)
                {
                    maxJump = max(maxJump, 1 + result);
                }
            }
        }
        return dp[index] = maxJump;
    }
    int maximumJumps(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> dp(n, -2);
        return rec(0, nums, target, dp);
    }
};