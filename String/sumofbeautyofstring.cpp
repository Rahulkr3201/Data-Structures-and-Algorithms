class Solution
{
public:
    int beautySum(string s)
    {

        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            unordered_map<char, int> mpp;
            for (int j = i; j < s.length(); j++)
            {
                int highest = INT_MIN;
                int lowest = INT_MAX;
                mpp[s[j]]++;

                for (auto it = mpp.begin(); it != mpp.end(); it++)
                {
                    highest = max(highest, it->second);
                    lowest = min(lowest, it->second);
                }
                sum = sum + (highest - lowest);
            }
        }
        return sum;
    }
};