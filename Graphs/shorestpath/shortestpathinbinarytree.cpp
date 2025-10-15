class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0}); // x, y, distance

        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;

        int ans = INT_MAX;

        // 8 directions
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty())
        {
            auto [x, y, dist] = q.front();
            q.pop();

            if (x == n - 1 && y == n - 1)
            {
                ans = min(ans, dist); // update ans
            }

            for (int k = 0; k < 8; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    grid[nx][ny] == 0 && !vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    q.push({nx, ny, dist + 1});
                }
            }
        }

        if (ans == INT_MAX)
            return -1;  // destination unreachable
        return ans + 1; // add 1 to account for starting cell
    }
};
