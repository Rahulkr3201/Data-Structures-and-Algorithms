class Solution
{
public:
    void dfs(int node, vector<vector<tuple<int, int>>> &graph, vector<bool> &visited, int mid)
    {
        visited[node] = true;
        for (int i = 0; i < graph[node].size(); i++)
        {
            int child, time;
            tie(child, time) = graph[node][i];

            // FIXED condition: only traverse "kept" edges
            if (!visited[child] && time > mid)
            {
                dfs(child, graph, visited, mid);
            }
        }
    }

    bool countStep(vector<vector<tuple<int, int>>> &graph, int mid, int k)
    {
        int count = 0;
        int n = graph.size();
        vector<bool> visited(n, false); // FIXED: declare visited fresh here

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(i, graph, visited, mid);
            }
        }
        cout << count << endl;
        cout << "mid " << mid << endl;
        cout << "k " << k << endl;
        if (count >= k)
            return true;
        return false;
    }

    int minTime(int n, vector<vector<int>> &edges, int k)
    {
        vector<vector<tuple<int, int>>> graph(n);
        int high = INT_MIN;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int time = edges[i][2];
            high = max(high, time);
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        int low = 0;
        int ans = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            cout << "mid here is " << mid << endl;
            if (countStep(graph, mid, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
