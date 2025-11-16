class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> temp(n, 0);
        int flip = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            if (i >= k)
            {
                flip = flip - temp[i - k];
            }

            int bit = nums[i] ^ (flip % 2);
            if (bit == 0)
            {
                if (i + k > n)
                    return -1;

                flip++;
                temp[i] = 1;
                ans++;
            }
        }
        return ans;
    }
};