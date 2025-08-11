class Solution
{
public:
    int recursion(vector<int> &coins, int index, int total)
    {
        // Base case
        if (index == 0)
        {
            if (total % coins[0] == 0)
                return total / coins[0];
            else
                return 1e9; // impossible
        }

        // Not taking the current coin
        int nottake = recursion(coins, index - 1, total);

        // Taking the current coin
        int take = 1e9;
        if (coins[index] <= total)
        {
            take = 1 + recursion(coins, index, total - coins[index]);
        }

        return min(take, nottake);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0; // no coins needed
        int n = coins.size();
        int ans = recursion(coins, n - 1, amount);
        return (ans >= 1e9) ? -1 : ans; // convert impossible case to -1
    }
};
