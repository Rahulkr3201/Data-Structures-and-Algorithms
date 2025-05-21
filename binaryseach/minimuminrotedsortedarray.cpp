class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int start = 0;
        int end = n - 1;
        int smallest = INT_MAX;

        while (start <= end && start >= 0 && end < n)
        {
            int mid = (start + end) / 2;

            if (nums[mid] - nums[start] >= 0)
            {
                smallest = min(smallest, nums[start]);
                start = mid + 1;
            }
            else if (nums[end] - nums[mid] >= 0)
            {
                smallest = min(smallest, nums[mid]);
                end = mid - 1;
            }
        }
        return smallest;
    }
};