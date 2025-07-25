class Solution
{
public:
    int dfs(int node, vector<vector<pair<int, int>>> &bigraph, vector<bool> &visited)
    {
        visited[node] = true;
        int count = 0;
        for (auto &child : bigraph[node])
        {
            int nextNode = child.first;
            int direction = child.second; // 1 if needs to reverse, 0 if already towards 0
            if (!visited[nextNode])
            {
                count += direction;
                count += dfs(nextNode, bigraph, visited);
            }
        }
        return count;
    }

    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pair<int, int>>> bigraph(n);
        // Build the graph with direction info: {neighbor, isOriginalDirection}
        for (auto &connection : connections)
        {
            int u = connection[0];
            int v = connection[1];
            bigraph[u].push_back({v, 1}); // original direction, needs to reverse when going out from 0
            bigraph[v].push_back({u, 0}); // reverse direction, no need to reverse
        }
        vector<bool> visited(n, false);
        return dfs(0, bigraph, visited);
    }
};