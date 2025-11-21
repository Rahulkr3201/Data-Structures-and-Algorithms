class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.length();
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            if (first[c] == -1)
                first[c] = i;
            last[c] = i;
        }
        int ans = 0;

        for (int i = 0; i < 26; i++)
        {
            if (first[i] == -1 || first[i] == last[i])
                continue;

            int L = first[i];
            int R = last[i];
            unordered_set<char> st;

            for (int j = L + 1; j < R; j++)
            {
                st.insert(s[j]);
            }
            ans = ans + st.size();
            st.empty();
        }
        return ans;
    }
};