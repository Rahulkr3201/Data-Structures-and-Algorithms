/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    unordered_map<TreeNode *, vector<TreeNode *>> graph;
    vector<int> results;
    void buildgraph(TreeNode *node, TreeNode *parent)
    {
        if (!node)
            return;
        if (parent)
        {
            graph[node].push_back(parent);
            graph[parent].push_back(node);
        }
        buildgraph(node->left, node);
        buildgraph(node->right, node);
    }
    void dfs(TreeNode *node, TreeNode *parent, int k, int dist)
    {
        if (dist == k)
            results.push_back(node->val);
        if (dist > k)
            return;

        for (auto neig : graph[node])
        {
            if (neig == parent)
                continue;
            dfs(neig, node, k, dist + 1);
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        buildgraph(root, nullptr);
        dfs(target, nullptr, k, 0);
        return results;
    }
};