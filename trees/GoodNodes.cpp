class Solution
{
public:
    int helper(TreeNode *root, int max)
    {
        int c = 0;
        int nMax = max;
        if (root == nullptr)
        {
            return 0;
        }
        if (root->val >= max)
        {
            c = 1;
            nMax = root->val;
        }
        return c + helper(root->left, nMax) + helper(root->right, nMax);
    }
    int goodNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int c = 1;
        return c + helper(root->left, root->val) + helper(root->right, root->val);
    }
};