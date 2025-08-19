class Solution
{
public:
    int cnt = 0;
    long long dfs(int node, int parent, vector<vector<int>> &graph, vector<int> &cost)
    {
        if (graph[node].size() == 1 && node != 0)
            return cost[node];

        long long maxi = 0;
        vector<long long> allChild;
        for (auto neig : graph[node])
        {
            if (neig == parent)
                continue;
            long long value = dfs(neig, node, graph, cost);
            allChild.push_back(value);
            maxi = max(maxi, value);
        }

        for (auto child : allChild)
        {
            if (child < maxi)
                cnt++;
        }
        return cost[node] + maxi;
    }
    int minIncrease(int n, vector<vector<int>> &edges, vector<int> &cost)
    {
        vector<vector<int>> graph(n);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1, graph, cost);
        return cnt;
    }
};