class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq; // stores indices, values in decreasing order

        for (int i = 0; i < nums.size(); i++)
        {
            // 1. Remove indices out of current window
            while (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // 2. Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            // 3. Push current index
            dq.push_back(i);

            // 4. If window is full, record the max
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};