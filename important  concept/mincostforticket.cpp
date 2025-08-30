class Solution
{
public:
    int solve(int i, vector<int> &days, vector<int> &costs, vector<int> &dp)
    {
        if (i >= days.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];
        int cost1 = costs[0] + solve(i + 1, days, costs, dp);

        int j = i;
        while (j < days.size() && days[i] + 6 >= days[j])
            j++;
        int cost7 = costs[1] + solve(j, days, costs, dp);

        int k = i;

        while (k < days.size() && days[i] + 29 >= days[k])
            k++;
        int cost30 = costs[2] + solve(k, days, costs, dp);

        return dp[i] = min({cost1, cost7, cost30});
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(0, days, costs, dp);
    }
};
