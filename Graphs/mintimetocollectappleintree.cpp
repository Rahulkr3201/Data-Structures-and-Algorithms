class Solution
{
public:
    int dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &hasApple)
    {
        visited[node] = true;
        int totalTime = 0;
        for (auto &neighbour : graph[node])
        {
            int childTime = 0;
            if (visited[neighbour] == false)
            {
                childTime = dfs(neighbour, graph, visited, hasApple);
                if (childTime > 0 || hasApple[neighbour])
                {
                    totalTime = totalTime + childTime + 2;
                }
            }
        }
        return totalTime;
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> graph(n);
        for (auto const &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n, false);
        return dfs(0, graph, visited, hasApple);
    }
};