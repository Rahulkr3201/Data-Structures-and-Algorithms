class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto time : times)
        {
            int u = time[0];
            int v = time[1];
            int timetaken = time[2];
            graph[u].push_back({v, timetaken});
        }

        vector<int> ans(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        ans[k] = 0;
        pq.push({0, k});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int t = top.first;
            int des = top.second;

            for (auto node : graph[des])
            {
                int currentnode = node.first;
                int nexttime = t + node.second;
                if (ans[currentnode] > nexttime)
                {
                    pq.push({nexttime, currentnode});
                    ans[currentnode] = nexttime;
                }
            }
        }

        int minTime = 0;
        for (int i = 1; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
            minTime = max(minTime, ans[i]);
        }
        return (minTime == INT_MAX) ? -1 : minTime;
    }
};