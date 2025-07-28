class Solution
{
public:
    int edgeScore(vector<int> &edges)
    {
        int n = edges.size();
        vector<long long> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            ans[edges[i]] = ans[edges[i]] + i;
        }

        int index;
        long long edgescore = INT_MIN;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] > edgescore)
            {
                edgescore = ans[i];
                index = i;
            }
        }
        return index;
    }
};