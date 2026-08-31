class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<int> tree;
        TreeNode *curr = root;
        while (curr != nullptr)
        {
            if (p->val > curr->val && q->val > curr->val)
            {
                curr = curr->right;
            }
            else if (p->val < curr->val && q->val < curr->val)
            {
                curr = curr->left;
            }
            else
            {
                return curr;
            }
        }
        return nullptr;
    }
};