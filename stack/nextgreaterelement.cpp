class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mpp;
        stack<int> st;
        vector<int> ans;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {

            while (!st.empty() && nums2[i] > st.top())
            {
                st.pop();
            }
            if (st.empty())
            {
                mpp[nums2[i]] = -1;
            }
            else
            {
                mpp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for (auto num : nums1)
        {
            ans.push_back(mpp[num]);
        }
        return ans;
    }
};