class Solution
{
public:
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited)
    {
        visited[node] = true;

        for (auto neigh : graph[node])
        {
            if (!visited[neigh])
                dfs(neigh, graph, visited);
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> graph(n);
        int edge = 0;
        for (auto connection : connections)
        {
            edge++;
            int u = connection[0];
            int v = connection[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if (edge < n - 1)
            return -1;
        vector<bool> visited(n, false);

        int connected = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, graph, visited);
                connected++;
            }
        }

        return connected - 1;
    }
};