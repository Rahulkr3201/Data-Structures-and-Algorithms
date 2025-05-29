class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        int count = 0;
        for (auto num : nums)
        {
            sum = sum + num;

            if (mpp.find(sum - k) != mpp.end())
            {
                count = count + mpp[sum - k];
            }
            mpp[sum]++;
        }
        return count;
    }
};