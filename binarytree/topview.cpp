#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void dfs(TreeNode *node, int col, int level, map<int, pair<int, int>> &topNodes)
    {
        if (!node)
            return;

        // If column not seen before or current level is higher (closer to top)
        if (topNodes.find(col) == topNodes.end() || level < topNodes[col].second)
        {
            topNodes[col] = {node->val, level};
        }

        dfs(node->left, col - 1, level + 1, topNodes);
        dfs(node->right, col + 1, level + 1, topNodes);
    }

    vector<int> topView(TreeNode *root)
    {
        map<int, pair<int, int>> topNodes;
        dfs(root, 0, 0, topNodes);

        vector<int> result;
        for (auto &it : topNodes)
        {
            result.push_back(it.second.first);
        }
        return result;
    }
};
/*
assign values of level,col using dfs and store in the map map<int,pair>>
using concept of level,column and checking there should be  only one value at every column , and
the value shoulde be of  less level for the top view*/
