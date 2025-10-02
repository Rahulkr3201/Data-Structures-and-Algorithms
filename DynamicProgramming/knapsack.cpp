// User function Template for C++

class Solution
{
public:
    // Recursion with memoization
    int recursion(int index, vector<int> &val, vector<int> &wt, int capacity, vector<vector<int>> &dp)
    {
        // If capacity goes below 0 → invalid
        if (capacity < 0)
            return INT_MIN;

        // If all items considered → no more profit can be added
        if (index == val.size())
            return 0;

        // Check memo table
        if (dp[index][capacity] != -1)
            return dp[index][capacity];

        // Option 1: take current item (unbounded → stay at same index)
        int take = val[index] + recursion(index, val, wt, capacity - wt[index], dp);

        // Option 2: skip current item
        int nottake = recursion(index + 1, val, wt, capacity, dp);

        // Store and return the maximum
        return dp[index][capacity] = max(take, nottake);
    }

    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        // DP table: dp[index][remaining_capacity]
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return recursion(0, val, wt, capacity, dp);
    }
};
