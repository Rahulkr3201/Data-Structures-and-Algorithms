class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int k = s1.size();
        vector<int> freq1(26);
        vector<int> freq2(26);

        for (auto it : s1)
        {
            freq1[it - 'a']++;
        }

        for (int i = 0; i < s2.size(); i++)
        {
            freq2[s2[i] - 'a']++;

            if (i >= k)
            {
                freq2[s2[i - k] - 'a']--;
            }
            if (freq1 == freq2)
                return true;
        }
        return false;
    }
};