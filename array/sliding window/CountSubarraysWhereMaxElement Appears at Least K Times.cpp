class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int largest = *max_element(nums.begin(), nums.end());
        vector<int> index;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == largest)
            {
                index.push_back(i);
            }
        }
        long long ans = 0;
        for (int i = 0; i < index.size(); i++)
        {
            int j = i + k - 1;
            if (j >= index.size())
                break;
            ;
            int leftmost = (i == 0 ? index[i] + 1 : index[i] - index[i - 1]);
            int rightmost = n - index[j];
            ans += 1LL * leftmost * rightmost;
        }
        return ans;
    }
};