class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int i = 0;
        int j = n - 1;

        int ans = 0;
        while (i < j)
        {
            int high = min(height[i], height[j]);
            int width = j - i;
            ans = max(ans, high * width);

            if (height[i] > height[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};