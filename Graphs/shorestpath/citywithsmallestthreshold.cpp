#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Distance matrix: dist[i][j] = shortest distance from i to j
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Run Dijkstra for each node
        for (int i = 0; i < n; i++)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});
            dist[i][i] = 0;

            while (!pq.empty())
            {
                auto [d, node] = pq.top();
                pq.pop();
                if (d > dist[i][node])
                    continue;

                for (auto &[nbr, wt] : adj[node])
                {
                    if (dist[i][nbr] > d + wt)
                    {
                        dist[i][nbr] = d + wt;
                        pq.push({dist[i][nbr], nbr});
                    }
                }
            }
        }

        // Find the city with the smallest number of reachable cities
        int minCount = INT_MAX, ans = -1;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j && dist[i][j] <= distanceThreshold)
                    count++;
            }
            if (count <= minCount)
            {
                // pick the city with the largest index in case of tie
                minCount = count;
                ans = i;
            }
        }

        return ans;
    }
};
