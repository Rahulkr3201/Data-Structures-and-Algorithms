class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        long long mod = 1e9 + 7;

        int n = nums.size();
        vector<long long> presum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            presum[i + 1] = presum[i] + nums[i];
        }

        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                left[i] = -1;
            }
            else
            {
                left[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                right[i] = n;
            }
            else
            {
                right[i] = st.top();
            }
            st.push(i);
        }
        long long maximum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            long long sum = presum[right[i]] - presum[left[i] + 1];
            // cout<<"sum"<<sum<<endl;
            long long product = (long long)sum * nums[i];
            // cout<<"product"<<product<<endl;
            maximum = max(maximum, product);
        }
        return (int)(maximum % mod);
    }
};