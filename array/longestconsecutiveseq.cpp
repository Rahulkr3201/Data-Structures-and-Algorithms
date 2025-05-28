class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        unordered_set<int> s;

        for (auto num : nums)
        {
            s.insert(num);
        }

        int ans = 1;
        for (auto it : s)
        {
            if (s.find(it - 1) != s.end())
            {
                continue;
            }
            else
            {
                int count = 1;
                int current = it;
                while (s.find(current + 1) != s.end())
                {
                    count++;
                    current = current + 1;
                }
                ans = max(ans, count);
            }
        }

        return ans;
    }
};