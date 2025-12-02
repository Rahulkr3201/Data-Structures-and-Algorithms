class Solution
{
public:
    int calculate(string s)
    {
        int num = 0;
        int result = 0;
        stack<pair<int, int>> st;
        int sign = 1;

        for (auto c : s)
        {

            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if (c == '+')
            {
                result = result + sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-')
            {
                result = result + sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(')
            {
                st.push({result, sign});
                result = 0;
                num = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                result = result + sign * num;
                num = 0;

                auto [prevResult, prevSign] = st.top();
                st.pop();
                result = prevResult + result * prevSign;
            }
        }
        result += sign * num;
        return result;
    }
};