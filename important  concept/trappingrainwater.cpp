class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        vector<int> leftmax(n), rightmax(n);

        leftmax[0] = height[0];
        for (int i = 1; i < n; i++)
            leftmax[i] = max(height[i], leftmax[i - 1]);

        rightmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightmax[i] = max(height[i], rightmax[i + 1]);

        int cover_area = 0;
        int block_area = 0;
        for (int i = 0; i < n; i++)
        {
            cover_area += min(leftmax[i], rightmax[i]);
            block_area += height[i];
        }

        return cover_area - block_area;
    }
};
