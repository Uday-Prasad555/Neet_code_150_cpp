class Solution
{
public:
    bool helper(TreeNode *node, TreeNode *nextNode)
    {
        if (node == nullptr && nextNode == nullptr)
        {
            return true;
        }
        if ((node != nullptr && nextNode != nullptr) && node->val == nextNode->val)
        {
            return helper(node->left, nextNode->left) && helper(node->right, nextNode->right);
        }
        return false;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (subRoot == nullptr)
        {
            return true;
        }
        if (root == nullptr)
        {
            return false;
        }
        if (helper(root, subRoot))
        {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};