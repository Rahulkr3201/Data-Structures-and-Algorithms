class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        unordered_map<int, int> mpp;
        long long mod = 1e9 + 7;

        for (auto &point : points)
        {
            int y = point[1];
            mpp[y]++;
        }

        vector<long long> possible; // changed to long long to avoid overflow

        for (auto &it : mpp)
        {
            long long n = it.second;
            long long combinations = (n * (n - 1)) / 2;
            possible.push_back(combinations % mod);
        }

        // REPLACE DOUBLE LOOP WITH FORMULA
        long long sum = 0;
        long long sumSq = 0;

        for (long long x : possible)
        {
            x = x % mod;
            sum = (sum + x) % mod;
            sumSq = (sumSq + (x * x) % mod) % mod;
        }

        long long result = (((sum * sum) % mod - sumSq + mod) % mod) * 500000004 % mod;
        // 500000004 = modular inverse of 2 under mod 1e9+7

        return (int)result;
    }
};