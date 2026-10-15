class KthLargest
{
public:
    int kl;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int> &nums)
    {
        kl = k;
        for (int x : nums)
        {
            pq.push(x);
            if (pq.size() > kl)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > kl)
        {
            pq.pop();
        }
        return pq.top();
    }
};