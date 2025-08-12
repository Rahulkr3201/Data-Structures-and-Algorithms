class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans;
        int counter = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                if (counter > 0)
                    ans.push_back(ch);
                counter++;
            }
            else
            {
                counter--;
                if (counter > 0)
                    ans.push_back(ch);
            }
        }

        return ans;
    }
};
