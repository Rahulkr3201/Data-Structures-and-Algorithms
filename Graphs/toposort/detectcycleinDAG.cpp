class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<int>> graph(V);
        vector<int> indegree(V, 0);

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int top = q.front();
            topo.push_back(top);
            q.pop();

            for (auto neigh : graph[top])
            {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        if (topo.size() == V)
            return false;

        return true;
        ;
    }
};