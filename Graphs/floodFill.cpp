class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        queue<pair<int, int>> q;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        q.push({sr, sc});
        visited[sr][sc] = 1;

        int initial = image[sr][sc];
        image[sr][sc] = color;

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {-1, 0, 1, 0};

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        visited[nx][ny] == 0 && image[nx][ny] == initial)
                    {
                        image[nx][ny] = color;
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return image;
    }
};