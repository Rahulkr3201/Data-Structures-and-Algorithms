class Solution
{
public:
    void dfs(int x, int y, vector<vector<int>> &visited, vector<vector<int>> &grid)
    {
        visited[x][y] = 1;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && visited[nx][ny] == 0 && grid[nx][ny] == 1)
            {
                dfs(nx, ny, visited, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 1 && visited[0][i] == 0)
            {
                dfs(0, i, visited, grid);
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (grid[n - 1][i] == 1 && visited[n - 1][i] == 0)
            {
                dfs(n - 1, i, visited, grid);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1 && visited[i][0] == 0)
            {
                dfs(i, 0, visited, grid);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (grid[i][m - 1] == 1 && visited[i][m - 1] == 0)
            {
                dfs(i, m - 1, visited, grid);
            }
        }
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0 && grid[i][j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};