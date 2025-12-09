#include <bits/stdc++.h>
using namespace std;

void dfsStack(int start, vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> vis(n, 0);
    stack<int> st;

    st.push(start);
    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (vis[top])
            continue;
        vis[top] = 1;
        cout << top << endl;

        for (int i = graph[top].size(); i >= 0; i--)
        {
            int neigh = graph[top][i];
            if (vis[neigh] == 0)
                st.push(neigh);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // remove if directed
    }

    dfsStack(0, graph);
}
