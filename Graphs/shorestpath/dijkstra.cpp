class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Code here
        vector<vector<pair<int, int>>> graph(V);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];

            graph[u].push_back({v, d});
            graph[v].push_back({u, d});
        }

        vector<int> dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node])
                continue;

            for (auto neigh : graph[node])
            {
                auto [nextnode, nextdis] = neigh;

                if (dis + nextdis < dist[nextnode])
                {
                    dist[nextnode] = dis + nextdis;
                    pq.push({dist[nextnode], nextnode});
                }
            }
        }
        return dist;
    }
};