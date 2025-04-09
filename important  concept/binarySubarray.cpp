class Solution
{
public:
    int atmost(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int count = 0;
        int sum = 0;
        while (left <= right && right < n)
        {
            sum = sum + nums[right];
            while (sum > goal)
            {
                sum = sum - nums[left];
                left++;
            }
            count = count + (right - left + 1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};