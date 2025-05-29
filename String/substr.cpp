class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0)
            return 0; // empty needle case

        for (int i = 0; i <= n - m; ++i)
        {
            if (haystack.substr(i, m) == needle) // substr give you substring
                // here it means find substring in haystack startinf from i and
                // length ==m and equal to needle
                return i;
        }

        return -1;
    }
};
