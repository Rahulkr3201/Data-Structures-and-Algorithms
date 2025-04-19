class Solution
{
public:
    void recursion(int index, int sum, vector<int> &candidates, int target,
                   vector<int> &temp, vector<vector<int>> &ans)
    {
        if (sum == target)
        {
            ans.push_back(temp);
            return;
        }
        if (sum > target)
            return;

        for (int i = index; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            recursion(i, sum + candidates[i], candidates, target, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        recursion(0, 0, candidates, target, temp, ans);
        return ans;
    }
};
// Start: recursion(0, 0, [], [2,3,6,7], ans)
│
├── Include 2 (temp=[2], sum=2)
│   │
│   ├── Include 2 (temp=[2,2], sum=4)
│   │   │
│   │   ├── Include 2 (temp=[2,2,2], sum=6)
│   │   │   │
│   │   │   ├── Include 2 → temp=[2,2,2,2], sum=8 ✗ (pruned)
│   │   │   ├── Include 3 → temp=[2,2,2,3], sum=9 ✗ (pruned)
│   │   │   ├── Include 6 → temp=[2,2,2,6], sum=12 ✗ (pruned)
│   │   │   └── Include 7 → temp=[2,2,2,7], sum=13 ✗ (pruned)
│   │   │
│   │   └── Exclude 2 (temp=[2,2], sum=4)
│   │       │
│   │       ├── Include 3 → temp=[2,2,3], sum=7 ✅ [2,2,3] (added to ans)
│   │       ├── Include 6 → temp=[2,2,6], sum=10 ✗ (pruned)
│   │       └── Include 7 → temp=[2,2,7], sum=11 ✗ (pruned)
│   │
│   └── Exclude 2 (temp=[2], sum=2)
│       │
│       ├── Include 3 → temp=[2,3], sum=5)
│       │   │
│       │   ├── Include 3 → temp=[2,3,3], sum=8 ✗ (pruned)
│       │   ├── Include 6 → temp=[2,3,6], sum=11 ✗ (pruned)
│       │   └── Include 7 → temp=[2,3,7], sum=12 ✗ (pruned)
│       │
│       └── Exclude 3 (temp=[2], sum=2)
│           │
│           ├── Include 6 → temp=[2,6], sum=8 ✗ (pruned)
│           └── Include 7 → temp=[2,7], sum=9 ✗ (pruned)
│
├── Include 3 (temp=[3], sum=3)
│   │
│   ├── Include 3 → temp=[3,3], sum=6)
│   │   │
│   │   ├── Include 3 → temp=[3,3,3], sum=9 ✗ (pruned)
│   │   ├── Include 6 → temp=[3,3,6], sum=12 ✗ (pruned)
│   │   └── Include 7 → temp=[3,3,7], sum=13 ✗ (pruned)
│   │
│   └── Exclude 3 (temp=[3], sum=3)
│       │
│       ├── Include 6 → temp=[3,6], sum=9 ✗ (pruned)
│       └── Include 7 → temp=[3,7], sum=10 ✗ (pruned)
│
├── Include 6 (temp=[6], sum=6)
│   │
│   ├── Include 6 → temp=[6,6], sum=12 ✗ (pruned)
│   └── Exclude 6 (temp=[6], sum=6)
│       │
│       └── Include 7 → temp=[6,7], sum=13 ✗ (pruned)
│
└── Include 7 (temp=[7], sum=7) ✅ [7] (added to ans)
//
