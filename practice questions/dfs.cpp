#include <bits/stdc++.h>
using namespace std;

void dfsRec(int node, vector<vector<int>> &graph, vector<int> &vis)
{
    vis[node] = 1;
    cout << node << " ";

    for (int neigh : graph[node])
    {
        if (!vis[neigh])
            dfsRec(neigh, graph, vis);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    // input edges (undirected graph)
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // remove this if graph is directed
    }

    vector<int> vis(n, 0);

    dfsRec(0, graph, vis);
}
