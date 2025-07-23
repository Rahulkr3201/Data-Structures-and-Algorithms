class Solution
{

    void even_gp(TreeNode *current, int &sum)
    {
        if (!current)
            return;

        if (current->val % 2 == 0)
        {
            if (current->left && current->left->left)
            {
                sum += current->left->left->val;
            }
            if (current->left && current->left->right)
            {
                sum += current->left->right->val;
            }
            if (current->right && current->right->left)
            {
                sum += current->right->left->val;
            }
            if (current->right && current->right->right)
            {
                sum += current->right->right->val;
            }
        }

        even_gp(current->left, sum);
        even_gp(current->right, sum);
    }

public:
    int sumEvenGrandparent(TreeNode *root)
    {
        int sum = 0;
        even_gp(root, sum);
        return sum;
    }
};
