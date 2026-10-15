class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int m;
        int n;
        priority_queue<int> pq;
        for (int x : stones)
        {
            pq.push(x);
        }
        while (pq.size() != 1)
        {
            m = pq.top();
            pq.pop();
            n = pq.top();
            pq.pop();
            pq.push(m - n);
        }
        return pq.top();
    }
};