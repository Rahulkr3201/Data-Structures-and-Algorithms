class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj)
    {
        int v = adj.size(); // Number of vertices
        vector<bool> visited(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                queue<pair<int, int>> q; // Declare the queue inside the `if` block
                q.push({i, -1});         // Push the starting node with parent as -1
                visited[i] = true;

                while (!q.empty())
                {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();

                    for (auto it : adj[node])
                    { // Use `node` instead of `i`
                        if (!visited[it])
                        {
                            q.push({it, node});
                            visited[it] = true; // Mark the node as visited before pushing
                        }
                        else if (it != parent)
                        {
                            // If the neighbor is visited and is not the parent, cycle exists
                            return true;
                        }
                    }
                }
            }
        }
        return false; // No cycle found
    }
};