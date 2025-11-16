class Solution
{
public:
    int numSub(string s)
    {
        int start = -1;
        long long ans = 0;
        const long long mod = 1e9 + 7;

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == '1')
            {
                if (start == -1)
                    start = i;
            }
            else
            {
                if (start != -1)
                {
                    int len = i - start;
                    long long val = (long long)len * (len + 1) / 2; // SAFE
                    ans = (ans + val) % mod;
                    start = -1;
                }
            }
        }

        if (start != -1)
        {
            int len = s.length() - start;
            long long val = (long long)len * (len + 1) / 2; // SAFE
            ans = (ans + val) % mod;
        }

        return ans;
    }
};