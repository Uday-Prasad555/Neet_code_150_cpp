class Solution
{
public:
    pair<int, bool> height(TreeNode *node)
    {

        if (node == nullptr)
        {
            return {0, true};
        }

        pair<int, bool> left = height(node->left);
        pair<int, bool> right = height(node->right);

        bool balanced = left.second &&
                        right.second &&
                        abs(left.first - right.first) <= 1;

        if (!balanced)
        {
            return {0, false};
        }

        return {1 + max(left.first, right.first), true};
    }

    bool isBalanced(TreeNode *root)
    {
        return height(root).second;
    }
};