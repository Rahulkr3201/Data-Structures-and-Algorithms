#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> product(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> product[i];
    }

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // BFS from port city 1
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : graph[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // Answer for each product type
    vector<int> ans(k + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int type = product[i];
        ans[type] = max(ans[type], dist[i]);
    }

    for (int i = 1; i <= k; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
