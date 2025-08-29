class Solution
{
public:
    bool canPlace(vector<int> &stalls, int mid, int k)
    {
        int count = 1;
        int temp = stalls[0];

        for (int i = 0; i < stalls.size(); i++)
        {
            if ((temp + mid) <= stalls[i])
            {
                count++;
                temp = stalls[i];
            }
        }
        if (count >= k)
            return true;
        else
            return false;
    }
    int aggressiveCows(vector<int> &stalls, int k)
    {
        // code here
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = (stalls[n - 1] - stalls[0]) / (k - 1);
        int ans = 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (canPlace(stalls, mid, k))
            {
                ans = mid;
                // cout<<"ans"<<ans<<endl;
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