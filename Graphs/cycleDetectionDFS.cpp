private:
bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    visited[node] = true;
    for (auto adjacent : adj[node])
    {
        if (!visited[adjacent])
        {
            if (dfs(adjacent, adj, visited, node) == true)
            {
                return true;
            };
        }
        else if (parent != adjacent)
        {
            return true;
        }
    }
    return false;
}

public:
bool isCycle(vector<vector<int>> &adj)
{
    int v = adj.size();
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, -1))
            {
                return true;
            };
        }
    }
    return false;
}