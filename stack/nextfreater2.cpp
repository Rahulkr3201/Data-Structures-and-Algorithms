class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int index = i % n;

            while (!st.empty() && st.top() <= nums[index])
            {
                st.pop();
            }

            if (!st.empty())
            {
                if (i < n)
                {
                    ans[index] = st.top();
                }
            }
            else
            {
                if (i < n)
                {
                    ans[index] = -1;
                }
            }

            st.push(nums[index]);
        }

        return ans;
    }
};
