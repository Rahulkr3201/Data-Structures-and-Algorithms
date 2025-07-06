class Solution
{
public:
    // DFS to collect connected components
    void dfs(int node, vector<vector<int>> &g, vector<bool> &visited, set<int> &component, int id, vector<int> &set_id)
    {
        visited[node] = true;
        component.insert(node);
        set_id[node] = id;
        for (int neighbour : g[node])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, g, visited, component, id, set_id); // FIXED: pass all args
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        // Step 1: Build graph
        vector<vector<int>> g(c + 1);
        for (auto &conn : connections)
        {
            g[conn[0]].push_back(conn[1]);
            g[conn[1]].push_back(conn[0]);
        }

        // Step 2: DFS to find components
        vector<bool> visited(c + 1, false); // FIXED: proper declaration
        vector<set<int>> component_sets;
        vector<int> set_id(c + 1, -1);

        int id = 0;
        for (int i = 1; i <= c; i++)
        {
            if (!visited[i])
            {
                set<int> component;
                dfs(i, g, visited, component, id, set_id);
                component_sets.push_back(component);
                id++;
            }
        }

        // Step 3: Process queries
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            int type = queries[i][0];
            int x = queries[i][1];

            if (type == 1)
            {
                int setNo = set_id[x];
                if (component_sets[setNo].find(x) != component_sets[setNo].end())
                {
                    ans.push_back(x); // x is in the set
                }
                else
                {
                    if (!component_sets[setNo].empty())
                    {
                        ans.push_back(*component_sets[setNo].begin()); // return smallest in set
                    }
                    else
                    {
                        ans.push_back(-1); // set is empty
                    }
                }
            }
            else if (type == 2)
            {
                int setNo = set_id[x];
                component_sets[setNo].erase(x); // remove x from its component set
            }
        }

        return ans;
    }
};
