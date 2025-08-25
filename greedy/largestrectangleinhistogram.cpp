class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        vector<int> right(n);
        vector<int> left(n);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[i] <= heights[st.top()])
            {
                st.pop();
            }
            left[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        while (!st.empty())
        {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            right[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            int width = right[i] - left[i] - 1;
            int area = width * heights[i];
            maxi = max(maxi, area);
        }
        return maxi;
    }
};