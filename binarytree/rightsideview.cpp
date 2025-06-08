/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void recursion(TreeNode *t1, int level, vector<int> &visited, vector<int> &ans)
    {
        if (t1 == NULL)
            return;
        if (visited[level] == -1)
        {
            ans.push_back(t1->val);
            visited[level] = 1;
        }

        recursion(t1->right, level + 1, visited, ans);
        recursion(t1->left, level + 1, visited, ans);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        vector<int> visited(102, -1);
        recursion(root, 1, visited, ans);
        return ans;
    }
};