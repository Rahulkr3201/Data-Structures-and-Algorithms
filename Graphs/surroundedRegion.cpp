class Solution
{
public:
    void dfs(int x, int y, vector<vector<int>> &visited, vector<vector<char>> &board)
    {
        visited[x][y] = 1;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && visited[nx][ny] == 0 && board[nx][ny] == 'O')
            {
                dfs(nx, ny, visited, board);
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == 'O' && visited[0][i] == 0)
            {
                dfs(0, i, visited, board);
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (board[n - 1][i] == 'O' && visited[n - 1][i] == 0)
            {
                dfs(n - 1, i, visited, board);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O' && visited[i][0] == 0)
            {
                dfs(i, 0, visited, board);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (board[i][m - 1] == 'O' && visited[i][m - 1] == 0)
            {
                dfs(i, m - 1, visited, board);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
                else
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};