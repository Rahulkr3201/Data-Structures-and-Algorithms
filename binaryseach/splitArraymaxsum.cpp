class Solution
{
public:
    int recursion(vector<int> nums, int mid)
    {
        int part = 1;
        int capacity = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            capacity = capacity + nums[i];
            if (capacity > mid)
            {
                part++;
                capacity = nums[i];
            }
        }
        return part;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            int part = recursion(nums, mid);
            if (part <= k)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};