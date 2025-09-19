class Solution
{
public:
    bool isPalindrome(string s)
    {

        int r = s.size();
        int l = 0;
        while (l < r)
        {
            while (l < r && !isalnum(s[l]))
                l++;
            while (l < r && !isalnum(s[r]))
                r--;
            if (tolower(s[l]) != tolower(s[r]))
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};