class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &color, bool black)
    {
        visited[node] = true;
        color[node] = black;
        int size = graph[node].size();
        for (int i = 0; i < size; i++)
        {
            int neighbour = graph[node][i];
            if (visited[neighbour])
            {
                if (color[neighbour] == color[node])
                    return false;
            }
            else
            {
                if (!dfs(neighbour, graph, visited, color, !black))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<bool> visited(n + 1, false);
        vector<int> color(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                if (dfs(i, graph, visited, color, 0) == false)
                    return false;
            }
        }
        return true;
    }
};
