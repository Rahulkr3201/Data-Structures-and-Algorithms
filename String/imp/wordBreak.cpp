class Solution
{
public:
    bool recursion(string s, unordered_set<string> &st, unordered_map<string, bool> &mpp)
    {
        if (s.empty())
            return true;
        if (mpp.count(s))
            return mpp[s];
        for (int len = 1; len <= s.size(); len++)
        {
            string prefix = s.substr(0, len);
            // cout<<"prefix"<<prefix<<endl;
            if (st.count(prefix))
            {
                int length = prefix.size();
                string suffix = s.substr(length);
                // cout<<"suffix"<<suffix<<endl;
                if (recursion(suffix, st, mpp))
                {
                    return mpp[s] = true;
                }
            }
        }
        return mpp[s] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {

        unordered_set<string> st(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> mpp;

        return recursion(s, st, mpp);
    }
};