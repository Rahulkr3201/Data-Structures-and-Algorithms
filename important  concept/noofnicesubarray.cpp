class Solution
{
public:
    int atmostodd(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0;
        int oddsum = 0;
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] % 2 != 0)
                oddsum++;

            while (oddsum > k)
            {
                if (nums[i] % 2 != 0)
                {
                    oddsum--;
                }
                i++;
            }
            count = count + (j - i) + 1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return atmostodd(nums, k) - atmostodd(nums, k - 1);
    }
};