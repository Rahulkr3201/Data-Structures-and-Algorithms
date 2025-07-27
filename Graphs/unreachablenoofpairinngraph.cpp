class Solution
{
public:
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, int &nodeSum)
    {
        visited[node] = true;
        nodeSum++;
        for (auto &child : graph[node])
        {
            if (!visited[child])
            {
                dfs(child, graph, visited, nodeSum);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n, false);
        long long ans = 0;
        long long notvisited = n;
        for (int i = 0; i < n; i++)
        {
            int nodeSum = 0;
            if (!visited[i])
            {
                dfs(i, graph, visited, nodeSum);
                long long available = notvisited - nodeSum;
                notvisited = available;
                ans += available * nodeSum;
            }
        }
        return ans;
    }
};