class Solution
{
public:
    bool helper(TreeNode *node, long long left, long long right)
    {
        if (node == nullptr)
        {
            return true;
        }
        if (!(node->val > left && node->val < right))
        {
            return false;
        }
        return helper(node->left, left, node->val) && helper(node->right, node->val, right);
    }
    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};