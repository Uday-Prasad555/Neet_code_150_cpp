class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});

        int ans = 0;

        while (!st.empty())
        {
            auto [curr, depth] = st.top();
            st.pop();

            ans = max(ans, depth);

            if (curr->left != nullptr)
                st.push({curr->left, depth + 1});

            if (curr->right != nullptr)
                st.push({curr->right, depth + 1});
        }

        return ans;
    }
};