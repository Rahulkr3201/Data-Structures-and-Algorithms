#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
    {
        int n = passingFees.size();

        vector<vector<pair<int, int>>> graph(n);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], t = e[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }

        vector<int> minTime(n, INT_MAX);

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({passingFees[0], 0, 0});
        minTime[0] = 0;

        while (!pq.empty())
        {
            auto [cost, timeSoFar, node] = pq.top();
            pq.pop();

            if (node == n - 1)
                return cost;

            for (auto &[nbr, t] : graph[node])
            {
                int newTime = timeSoFar + t;
                if (newTime <= maxTime && newTime < minTime[nbr])
                {
                    minTime[nbr] = newTime;
                    pq.push({cost + passingFees[nbr], newTime, nbr});
                }
            }
        }

        return -1;
    }
};
