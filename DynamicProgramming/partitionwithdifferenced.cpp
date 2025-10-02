class Solution
{
public:
    int recursion(int index, vector<int> &arr, int needed, int sum, vector<vector<int>> &dp)
    {
        if (index == arr.size())
        {
            return (sum == needed) ? 1 : 0;
        }
        if (dp[index][sum] != -1)
            return dp[index][sum];

        int take = 0;
        if (sum + arr[index] <= needed)
        {
            take = recursion(index + 1, arr, needed, sum + arr[index], dp);
        }

        int notTake = recursion(index + 1, arr, needed, sum, dp);

        return dp[index][sum] = take + notTake;
    }

    int countPartitions(vector<int> &arr, int d)
    {
        int total = accumulate(arr.begin(), arr.end(), 0);

        // impossible cases
        if ((total + d) % 2 != 0)
            return 0;
        if (d > total)
            return 0;

        int needed = (total + d) / 2; // this s1-s2=d and s1+s2=total give me s1=(total+d)/2;
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(needed + 1, -1));
        return recursion(0, arr, needed, 0, dp);
    }
};
