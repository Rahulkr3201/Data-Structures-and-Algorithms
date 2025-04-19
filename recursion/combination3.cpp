
class Solution
{
public:
    void recursion(int index, int sum, int k, int n, vector<int> &temp, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (sum == n && temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        if (sum > n || index >= nums.size())
            return;
        temp.push_back(nums[index]);
        recursion(index + 1, sum + nums[index], k, n, temp, nums, ans);
        temp.pop_back();
        recursion(index + 1, sum, k, n, temp, nums, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> temp;
        vector<vector<int>> ans;
        recursion(0, 0, k, n, temp, nums, ans);
        return ans;
    }
};
Start : recursion(0, 0, [], [1 - 9], ans)
│
├── Include 1(temp = [1], sum = 1)
│   │
│   ├── Include 2(temp = [ 1, 2 ], sum = 3)
│   │   │
│   │   ├── Include 3(temp = [ 1, 2, 3 ], sum = 6) 
│   │   │   ├── Include 4 → sum = 10 ✗ (stop)
│   │   │   └── Exclude 4 → sum = 6, size = 3 ✗ (stop)
│   │   │
│   │   └── Exclude 3(temp = [ 1, 2 ], sum = 3)
│   │       │
│   │       ├── Include 4(temp = [ 1, 2, 4 ], sum = 7) → ✅ [1, 2, 4]
│   │       └── Exclude 4(temp = [ 1, 2 ], sum = 3) → continues...
│   │
│   └── Exclude 2(temp = [1], sum = 1)
│       │
│       ├── Include 3(temp = [ 1, 3 ], sum = 4)
│       │   ├── Include 4 → sum = 8 ✗
│       │   └── Exclude 4 → continues...
│       │
│       └── Exclude 3(temp = [1], sum = 1) → continues...
│
└── Exclude 1(temp = [], sum = 0)
    │
    ├── Include 2(temp = [2], sum = 2)
    │   │
    │   ├── Include 3(temp = [ 2, 3 ], sum = 5)
    │   │   ├── Include 4 → sum = 9 ✗
    │   │   └── Exclude 4 → continues...
    │   │
    │   └── Exclude 3(temp = [2], sum = 2) → continues...
    │
    └── Exclude 2(temp = [], sum = 0) → continues...