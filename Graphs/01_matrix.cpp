class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int dis = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, dis});
                    visited[i][j] = 1;
                }
            }
        }
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[x][y] = dis;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] != 1)
                {
                    q.push({{nx, ny}, dis + 1});
                    visited[nx][ny] = 1;
                }
            }
        }
        return ans;
    }
};