class Solution
{
public:
    int integerReplacement(int n)
    {
        long long num = n; // use long long to handle overflow (when n = INT_MAX)
        int cnt = 0;

        while (num != 1)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                // Special case: if num = 3 or num % 4 == 1, subtracting is better
                if (num == 3 || num % 4 == 1)
                {
                    num -= 1;
                }
                else
                {
                    num += 1;
                }
            }
            cnt++;
        }
        return cnt;
    }
};
