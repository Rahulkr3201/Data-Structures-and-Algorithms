class Solution
{
public:
    int dfs(int u, vector<vector<int>> &graph, vector<int> &quiet, vector<int> &answer)
    {
        if (answer[u] != -1)
            return answer[u]; // already computed

        int minPerson = u; // start with the person themselves
        for (int v : graph[u])
        {
            int cand = dfs(v, graph, quiet, answer); // recurse to richer neighbor
            if (quiet[cand] < quiet[minPerson])
            {
                minPerson = cand;
            }
        }

        answer[u] = minPerson; // store only the final quietest person
        return answer[u];
    }

    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        vector<int> answer(n, -1); // -1 = not computed yet

        // Build graph: poorer -> richer
        for (auto &r : richer)
        {
            int poor = r[1], rich = r[0];
            graph[poor].push_back(rich);
        }

        // Run DFS for all nodes
        for (int i = 0; i < n; i++)
        {
            dfs(i, graph, quiet, answer);
        }

        return answer;
    }
};
