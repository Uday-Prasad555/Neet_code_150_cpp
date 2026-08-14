class LRUCache
{
public:
    struct Node
    {
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int k, int v)
        {
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };
    int capacity;
    unordered_map<int, Node *> hm;
    Node *head;
    Node *tail;
    void remove(Node *n)
    {
        n->next->prev = n->prev;
        n->prev->next = n->next;
    }
    void insert(Node *n)
    {
        Node *curr = head->next;
        head->next = n;
        n->prev = head;
        n->next = curr;
        curr->prev = n;
    }

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (hm.find(key) == hm.end())
        {
            return -1;
        }
        Node *node = hm[key];
        remove(node);
        insert(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (hm.find(key) != hm.end())
        {
            Node *node = hm[key];
            node->val = value;
            remove(node);
            insert(node);
            return;
        }
        Node *newNode = new Node(key, value);
        hm[key] = newNode;
        insert(newNode);
        if (hm.size() > capacity)
        {
            Node *lru = tail->prev;
            remove(lru);
            hm.erase(lru->key);
            delete lru;
        }
    }
};