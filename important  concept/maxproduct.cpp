class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            prefix = prefix == 0 ? 1 : prefix;
            suffix = suffix == 0 ? 1 : suffix;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            maxi = max(maxi, max(prefix, suffix));
        }

        return maxi;
    }
};
