class Solution
{
public:
    string reverseWords(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        string temp = "";
        string ans = "";

        while (left <= right)
        {
            char ch = s[left];
            if (ch != ' ')
            {
                temp += ch;
            }
            else if (ch == ' ' && temp != "")
            {
                if (ans != "")
                    ans = temp + " " + ans; // in c++ + operator return new string you have to store it for further use;
                else
                    ans = temp;
                temp = "";
            }
            left++;
        }

        if (temp != "")
        {
            if (ans != "")
                ans = temp + " " + ans;
            else
                ans = temp;
        }

        return ans;
    }
};
