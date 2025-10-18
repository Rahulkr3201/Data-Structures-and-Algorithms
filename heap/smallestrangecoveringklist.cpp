class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minheap;

        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            minheap.push({nums[i][0], i, 0});
            maxi = max(maxi, nums[i][0]);
        }

        vector<int> ans(2, 0);
        int finallen = INT_MAX;

        while (minheap.size() == n)
        {
            auto [mini, row, col] = minheap.top();
            minheap.pop();

            int len = maxi - mini;
            if (len < finallen)
            {
                finallen = len;
                ans[0] = mini;
                ans[1] = maxi;
            }

            if (col + 1 < nums[row].size())
            {
                minheap.push({nums[row][col + 1], row, col + 1});
                maxi = max(maxi, nums[row][col + 1]);
            }
        }

        return ans;
    }
};
