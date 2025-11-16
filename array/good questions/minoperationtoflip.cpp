class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int flip = 0;

        for (int i = 0; i < n; i++)
        {

            if (nums[i] == 0)
            {
                if (i + 3 > n)
                    return -1;

                for (int j = i; j < i + 3; j++)
                {
                    if (nums[j] == 0)
                        nums[j] = 1;
                    else
                        nums[j] = 0;
                }
                flip++;
            }
        }
        return flip;
    }
};