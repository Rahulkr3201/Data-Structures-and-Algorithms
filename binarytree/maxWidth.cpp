class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        // Pair of node and its index
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 1});
        int maxWidth = 0;

        while (!q.empty())
        {
            int size = q.size();
            unsigned long long rightmost = 0;
            unsigned long long leftmost = 0;

            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front().first;
                unsigned long long value = q.front().second;
                if (i == 0)
                    leftmost = value;
                if (i == size - 1)
                    rightmost = value;
                q.pop();
                if (temp->left)
                    q.push({temp->left, value * 2});
                if (temp->right)
                    q.push({temp->right, (value * 2) + 1});
            }
            int width = (rightmost - leftmost) + 1;
            maxWidth = max(width, maxWidth);
        }

        return maxWidth;
    }
};
