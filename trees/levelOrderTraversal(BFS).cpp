class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> sol;

        if (root == nullptr)
        {
            return {};
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int l = q.size();
            vector<int> level;

            for (int i = 0; i < l; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left != nullptr)
                    q.push(curr->left);

                if (curr->right != nullptr)
                    q.push(curr->right);
            }

            sol.push_back(level);
        }

        return sol;
    }
};