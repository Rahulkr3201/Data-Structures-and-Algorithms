class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int start = 1;
        int end = n - 2;
        if (n == 1)
            return nums[0];

        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (nums[mid] == nums[mid - 1])
            {
                if ((mid - 1) % 2 == 0)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 2;
                }
            }
            else if (nums[mid] == nums[mid + 1])
            {
                if (mid % 2 == 0)
                {
                    start = mid + 2;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else
            {
                return nums[mid];
            }
        }

        return -1;
    }
};
