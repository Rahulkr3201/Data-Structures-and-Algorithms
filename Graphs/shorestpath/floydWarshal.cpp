#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

        // Distance from a city to itself is 0
        for (int i = 0; i < n; i++)
        {
            graph[i][i] = 0;
        }

        // Fill initial edge weights
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];
            graph[u][v] = d;
            graph[v][u] = d;
        }

        // Floyd–Warshall algorithm
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (graph[i][via] == INT_MAX || graph[via][j] == INT_MAX)
                        continue;
                    graph[i][j] = min(graph[i][j], graph[i][via] + graph[via][j]);
                }
            }
        }

        int ans = -1;
        int mincount = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j && graph[i][j] <= distanceThreshold)
                    count++;
            }
            if (count <= mincount)
            {
                mincount = count;
                ans = i;
                cout << "i" << i << "ans" << ans << endl;
            }
        }

        return ans;
    }
};
