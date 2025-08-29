class Solution
{
public:
    int recursion(int index, vector<pair<int, int>> &v, vector<int> &newStart)
    {
        int n = newStart.size();
        if (index == n)
            return 0;

        int newIndex = lower_bound(newStart.begin(), newStart.end(), v[index].second) - newStart.begin();
        int take = 1 + recursion(newIndex, v, newStart);

        int nottake = recursion(index + 1, v, newStart);
        return max(take, nottake);
    }

    int activitySelection(vector<int> &start, vector<int> &finish)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < start.size(); i++)
        {
            v.push_back({start[i], finish[i]});
        }
        sort(v.begin(), v.end());
        vector<int> newStart;
        for (auto val : v)
        {
            newStart.push_back(val.first);
        }

        return recursion(0, v, newStart);
    }
};
// now the dp solution is given
class Solution
{
public:
    int recursion(int index, vector<pair<int, int>> &v, vector<int> &newStart, vector<int> &dp)
    {
        int n = newStart.size();
        if (index == n)
            return 0;

        if (dp[index] != -1)
            return dp[index]; // check memo

        // Find next activity whose start >= current finish
        int newIndex = lower_bound(newStart.begin(), newStart.end(), v[index].second) - newStart.begin();

        int take = 1 + recursion(newIndex, v, newStart, dp); // take current activity
        int nottake = recursion(index + 1, v, newStart, dp); // skip current activity

        return dp[index] = max(take, nottake);
    }

    int activitySelection(vector<int> &start, vector<int> &finish)
    {
        int n = start.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({start[i], finish[i]});
        }

        sort(v.begin(), v.end()); // sort by start time

        vector<int> newStart;
        for (auto val : v)
        {
            newStart.push_back(val.first);
        }

        vector<int> dp(n, -1); // memoization array

        return recursion(0, v, newStart, dp);
    }
};
