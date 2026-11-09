class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        unordered_map<Node *, Node *> hm;
        auto clone = [&](auto &&self, Node *node) -> Node *
        {
            if (hm.count(node))
                return hm[node];
            Node *copy = new Node(node->val);
            hm[node] = copy;
            for (auto x : node->neighbors)
            {
                copy->neighbors.push_back(self(self, x));
            }
            return copy;
        };
        return clone(clone, node);
    }
};