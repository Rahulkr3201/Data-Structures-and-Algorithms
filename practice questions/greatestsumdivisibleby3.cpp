class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> r1;
        vector<int> r2;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
            if (nums[i] % 3 == 1)
                r1.push_back(nums[i]);
            if (nums[i] % 3 == 2)
                r2.push_back(nums[i]);
        }
        if (sum % 3 == 0)
            return sum;
        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());
        int res = 0;
        if (sum % 3 == 1)
        {
            int option1 = (r1.size() >= 1) ? r1[0] : INT_MAX;
            int option2 = (r2.size() >= 2) ? r2[0] + r2[1] : INT_MAX;
            res = min(option1, option2);
            cout << "res" << res << endl;
        }
        else
        {
            int option1 = (r2.size() >= 1) ? r2[0] : INT_MAX;
            int option2 = (r1.size() >= 2) ? r1[0] + r1[1] : INT_MAX;
            res = min(option1, option2);
        }
        cout << "res" << res << endl;
        return (res == INT_MAX) ? 0 : (sum - res);
    }
};