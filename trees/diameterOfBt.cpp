class Solution
{
public:
    int c = 0;

    int height(TreeNode *node)
    {
        if (node == nullptr)
        {
            return -1;
        }

        int L = height(node->left);
        int R = height(node->right);

        c = max(c, L + R + 2);

        return 1 + max(L, R);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        height(root);
        return c;
    }
};