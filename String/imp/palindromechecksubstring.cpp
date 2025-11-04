class Solution
{
public:
    bool palindrome(string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        int n = s.length();
        int maxlen = 1;
        int index = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (j - i + 1 > maxlen && palindrome(s, i, j))
                {
                    maxlen = j - i + 1;
                    index = i;
                }
            }
        }
        return s.substr(index, maxlen);
    }
};