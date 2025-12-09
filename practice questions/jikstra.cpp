#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> graph[], int S, vector<int> &parent)
    {

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(V, 1e9);
        dist[S] = 0;

        parent[S] = -1; // source has no parent

        pq.push({0, S});

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : graph[node])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];

                if (dis + edgeWeight < dist[adjNode])
                {

                    dist[adjNode] = dis + edgeWeight;

                    parent[adjNode] = node; // store parent for path

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

// Function to print path from source to any destination
vector<int> getPath(int dest, vector<int> &parent)
{
    vector<int> path;

    while (dest != -1)
    {
        path.push_back(dest);
        dest = parent[dest];
    }

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph[V];
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int S;
    cin >> S;

    vector<int> parent(V, -1);

    Solution obj;
    vector<int> dist = obj.dijkstra(V, graph, S, parent);

    // Print distances
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << " : Distance = " << dist[i] << " , Path = ";

        vector<int> path = getPath(i, parent);

        for (int x : path)
            cout << x << " ";
        cout << "\n";
    }
}
