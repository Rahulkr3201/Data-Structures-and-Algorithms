class Solution
{
public:
    bool canPlace(vector<int> &position, int mid, int m)
    {
        int count = 1;
        int temp = position[0];

        for (int i = 1; i < position.size(); i++)
        {
            if ((position[i] - temp) >= mid)
            {
                count++;
                temp = position[i];
            }
        }
        if (count >= m)
            return true;
        return false;
    }
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 1;
        int high = (position[n - 1] - position[0]) / (m - 1);
        int ans = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canPlace(position, mid, m))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};