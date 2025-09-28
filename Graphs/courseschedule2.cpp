class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph and indegree array
        for (auto &pre : prerequisites)
        {
            graph[pre[1]].push_back(pre[0]); // b -> a
            indegree[pre[0]]++;              // a has one more prerequisite
        }

        queue<int> q;
        // Add all courses with 0 prerequisites
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            topo.push_back(course);

            for (int next : graph[course])
            {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return topo.size() == numCourses ? topo : vector<int>();
    }
};
