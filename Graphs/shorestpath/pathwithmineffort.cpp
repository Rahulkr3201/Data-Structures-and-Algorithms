class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});

        effort[0][0] = 0;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int dist, x, y;
            tie(dist, x, y) = top;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                {
                    int diff = abs(heights[nx][ny] - heights[x][y]);
                    int absmax = max(diff, dist);
                    if (absmax < effort[nx][ny])
                    {
                        effort[nx][ny] = absmax;
                        pq.push({absmax, nx, ny});
                    }
                }
            }
        }
        return effort[n - 1][m - 1];
    }
};