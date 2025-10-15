class Solution
{
public:
    bool ishero(int index, vector<vector<int>> &mat)
    {

        for (int i = 0; i < mat.size(); i++)
        {
            if (i != index && mat[i][index] != 1)
                return false;
        }
        return true;
    }

    int celebrity(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();

        vector<int> possible(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && mat[i][j] == 1)
                    possible[i] = -1;
            }
        }

        for (int i = 0; i < possible.size(); i++)
        {
            if (possible[i] == 0)
            {
                if (ishero(i, mat))
                    return i;
            }
        }
        return -1;
    }
};