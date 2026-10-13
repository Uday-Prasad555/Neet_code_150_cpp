class Codec
{
public:
    string serialize(TreeNode *root)
    {
        string data = "";

        function<void(TreeNode *)> dfs = [&](TreeNode *node)
        {
            if (node == nullptr)
            {
                data += "N,";
                return;
            }

            data += to_string(node->val) + ",";
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);
        return data;
    }

    TreeNode *deserialize(string data)
    {
        int i = 0;
        vector<string> dv;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ','))
        {
            dv.push_back(token);
        }
        function<TreeNode *()> dfs = [&]() -> TreeNode *
        {
            if (dv[i] == "N")
            {
                i = i + 1;
                return nullptr;
            }
            int val = stoi(dv[i]);
            TreeNode *node = new TreeNode(val);
            i = i + 1;
            node->left = dfs();
            node->right = dfs();
            return node;
        };
        return dfs();
    }
};
