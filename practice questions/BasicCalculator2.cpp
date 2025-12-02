class Solution
{
public:
    int calculate(string s)
    {
        int result = 0;
        int num = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++)
        {

            if (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }

            else if (s[i] == '+' || s[i] == '-')
            {
                result += sign * num;
                num = 0;
                sign = (s[i] == '+') ? 1 : -1;
            }

            else if (s[i] == '*' || s[i] == '/')
            {

                int j = i + 1;
                while (j < s.length() && s[j] == ' ')
                    j++;

                int nextNum = 0;
                while (j < s.length() && isdigit(s[j]))
                {
                    nextNum = nextNum * 10 + (s[j] - '0');
                    j++;
                }

                if (s[i] == '*')
                    num = num * nextNum;
                else
                    num = num / nextNum;

                i = j - 1;
            }
        }

        result += sign * num;
        return result;
    }
};
