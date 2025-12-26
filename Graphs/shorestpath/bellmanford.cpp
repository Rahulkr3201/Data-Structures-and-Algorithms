class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8); // Initialize distances to "infinity"
        dist[S] = 0;              // Distance to source is 0

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; i++)
        {
            for (auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycles
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                return {-1}; // Negative cycle detected, even after removing till n-1 step we are getting it removed for nth means we are stuck in loop.
                        }
        }

        return dist;
    }
};
