class Solution
{
public:
    void combination(int index, string digits, unordered_map<char, string> mpp, string &temp, vector<string> &ans)
    {
        if (temp.length() == digits.length())
        {
            ans.push_back(temp);
        }
        string letter = mpp[digits[index]];
        for (int j = 0; j < letter.length(); j++)
        {
            temp.push_back(letter[j]);
            combination(index + 1, digits, mpp, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> mpp;
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        string temp;
        combination(0, digits, mpp, temp, ans);
        return ans;
    }
};