class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int count = 0;
        int largest = INT_MIN;
        for (auto pair : pairs)
        {
            if (pair[0] > largest)
            {
                count++;
                largest = pair[1];
            }
        }

        return count;
    }
};
