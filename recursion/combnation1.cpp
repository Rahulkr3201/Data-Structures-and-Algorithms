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
