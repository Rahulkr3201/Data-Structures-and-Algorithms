class Solution
{
public:
    string smallestPalindrome(string s)
    {
        if (s.length() == 1)
            return s;

        int n = s.length();
        string ans(n, ' ');

        map<char, int> mpp;
        for (auto it : s)
        {
            mpp[it]++;
        }

        int i = 0;
        for (auto it = mpp.begin(); it != mpp.end(); it++)
        {
            if ((it->second) % 2 != 0)
            {
                ans[n / 2] = it->first;
            }
            int len = (it->second) / 2;
            while (len > 0)
            {
                ans[i] = it->first;
                ans[n - i - 1] = it->first;
                i++;
                len--;
            }
        }
        return ans;
    }
};
