#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        // Min-heap of tuple {value, row, col}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;

        // Push the first element of each row
        for (int i = 0; i < n; i++)
        {
            minHeap.push({matrix[i][0], i, 0});
        }

        int value = -1;
        while (k--)
        {
            int row, col;
            tie(value, row, col) = minHeap.top(); // unpack tuple
            minHeap.pop();

            if (col + 1 < n)
            {
                // Push the next element in the same row
                minHeap.push({matrix[row][col + 1], row, col + 1});
            }
        }

        return value;
    }
};
