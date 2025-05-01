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

        int take = nums[n] + recursion(n - 2, nums, dp);
        int nottake = 0 + recursion(n - 1, nums, dp);

        return dp[n] = max(take, nottake);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        vector<int> dp1(nums1.size() + 1, -1);
        vector<int> dp2(nums2.size() + 1, -1);

        int ans1 = recursion(nums1.size() - 1, nums1, dp1);
        int ans2 = recursion(nums2.size() - 1, nums2, dp2);

        return max(ans1, ans2);
    }
};