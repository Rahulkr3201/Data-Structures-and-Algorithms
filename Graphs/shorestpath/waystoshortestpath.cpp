class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);

        // Build graph
        for (auto &road : roads)
        {
            int u = road[0];
            int v = road[1];
            int t = road[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }

        // Min-heap: {time, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> time(n, LLONG_MAX); // shortest time to node
        vector<long long> ways(n, 0);         // number of shortest paths to node

        time[0] = 0;
        ways[0] = 1; // 1 way to reach start
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [timetaken, node] = pq.top();
            pq.pop();

            // Removed the check: if(timetaken > time[node]) continue;

            for (auto &[nextNode, edgeTime] : graph[node])
            {
                long long newtime = timetaken + edgeTime;

                if (newtime < time[nextNode])
                {
                    // Found shorter path
                    time[nextNode] = newtime;
                    ways[nextNode] = ways[node]; // only ways from this node
                    pq.push({newtime, nextNode});
                }
                else if (newtime == time[nextNode])
                {
                    // Found another shortest path
                    ways[nextNode] = (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD; // number of shortest paths to destination
    }
};
