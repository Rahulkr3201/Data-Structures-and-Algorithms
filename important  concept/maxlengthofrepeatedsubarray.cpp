class Solution
{
public:
    int ans = 0;

    int recursion(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (i == nums1.size() || j == nums2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (nums1[i] == nums2[j])
        {
            dp[i][j] = 1 + recursion(i + 1, j + 1, nums1, nums2, dp);
            ans = max(ans, dp[i][j]); // update global max
        }
        else
        {
            dp[i][j] = 0;
        }

        // still need to explore other positions
        recursion(i + 1, j, nums1, nums2, dp);
        recursion(i, j + 1, nums1, nums2, dp);

        return dp[i][j];
    }

    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        recursion(0, 0, nums1, nums2, dp);

        return ans;
    }
};
