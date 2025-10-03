class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &color)
    {
        if (color[node] != 0)
        {
            return color[node] == 2;
        }
        color[node] = 1;
        for (auto neigh : graph[node])
        {
            if (dfs(neigh, graph, color) == false)
            {
                return false;
            }
        }
        color[node] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (dfs(i, graph, color))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};