class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<pair<int, int>> v;
        vector<int> choco(n, 0);

        for (int i = 0; i < n; i++)
        {
            v.push_back({ratings[i], i});
        }

        sort(v.begin(), v.end());

        for (auto &p : v)
        {
            int i = p.second;
            int left = (i - 1 >= 0 && ratings[i] > ratings[i - 1]) ? choco[i - 1] : 0;
            int right = (i + 1 < n && ratings[i] > ratings[i + 1]) ? choco[i + 1] : 0;
            choco[i] = 1 + max(left, right);
        }

        int ans = 0;
        for (int x : choco)
            ans += x;
        return ans;
    }
};
