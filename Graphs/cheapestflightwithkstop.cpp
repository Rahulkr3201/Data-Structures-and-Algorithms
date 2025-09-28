

class Solution
{
public:
    int ans = INT_MAX;

    void dfs(int src, int dst, vector<vector<pair<int, int>>> &graph,
             int count, int k, int cost, vector<vector<int>> &dp)
    {

        if (src == dst)
        {
            ans = min(ans, cost);
            return;
        }
        if (count > k)
            return;

        for (auto child : graph[src])
        {
            int nextIndex = child.first;
            int nextprice = cost + child.second; // ✅ add to cost

            if (nextprice < dp[nextIndex][count + 1])
            {
                dp[nextIndex][count + 1] = nextprice;
                dfs(nextIndex, dst, graph, count + 1, k, nextprice, dp); // ✅ semicolon
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto flight : flights)
        {
            int u = flight[0], v = flight[1], price = flight[2];
            graph[u].push_back({v, price});
        }

        vector<vector<int>> dp(n, vector<int>(k + 2, INT_MAX)); // ✅ semicolon
        dfs(src, dst, graph, 0, k, 0, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};
