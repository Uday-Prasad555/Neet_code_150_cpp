class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> st;
        TreeNode *curr = root;
        int c = 0;
        while (curr != nullptr || !st.empty())
        {
            while (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            c++;
            if (k == c)
            {
                return curr->val;
            }
            curr = curr->right;
        }

        return -1;
    }
};