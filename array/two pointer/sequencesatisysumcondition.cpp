#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Precompute all powers of 2 up to n
        vector<long long> pow2(n, 1);
        for (int k = 1; k < n; k++)
        {

            pow2[k] = (pow2[k - 1] * 2) % MOD;
        }

        int i = 0, j = n - 1;
        long long ans = 0;

        while (i <= j)
        {
            if (nums[i] + nums[j] > target)
                j--;
            else
            {
                ans = (ans + pow2[j - i]) % MOD;
                i++;
            }
        }
        return ans;
    }
};
