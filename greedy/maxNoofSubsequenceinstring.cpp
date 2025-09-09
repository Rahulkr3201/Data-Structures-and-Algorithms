class Solution
{
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        int count0 = 0;
        int count1 = 0;
        long long total = 0;

        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == pattern[1])
            {
                total = total + count0;
                count1++;
            }
            if (text[i] == pattern[0])
            {
                count0++;
            }
        }
        long long option1 = total + count1;
        long long option2 = total + count0;
        return max(option1, option2);
    }
};