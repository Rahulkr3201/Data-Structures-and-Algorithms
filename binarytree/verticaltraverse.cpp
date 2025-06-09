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
    // Map: column -> (level -> multiset of node values)
    map<int, map<int, multiset<int>>> nodes;

    void dfs(TreeNode *node, int col, int level)
    {
        if (!node)
            return;

        nodes[col][level].insert(node->val);

        dfs(node->left, col - 1, level + 1);
        dfs(node->right, col + 1, level + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        dfs(root, 0, 0);

        vector<vector<int>> result;

        for (auto &[column, levelMap] : nodes)
        {
            vector<int> colvalues;
            for (auto &[levels, levelvalues] : levelMap)
            {
                colvalues.insert(colvalues.end(), levelvalues.begin(), levelvalues.end());
            }
            result.push_back(colvalues);
        }

        return result;
    }
};
/*
we are using dfs or bfs to assign value of level and column to eachh nodes.
then we use map<int, map<int,multiset<int>>> multiset beacuse we want to put values in sorted manner so set is sorted and for
dupllicate multiset . first map is for column and inside it for levels as levels can be multiple for each col.
*/
