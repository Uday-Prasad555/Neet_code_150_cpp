class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> hm;
        for (char x : tasks)
        {
            hm[x]++;
        }

        priority_queue<int> pq;
        for (auto i : hm)
        {
            pq.push(i.second);
        }

        queue<pair<int, int>> q;
        int time = 0;

        while (!pq.empty() || !q.empty())
        {
            time++;

            if (!pq.empty())
            {
                int a = pq.top() - 1;
                pq.pop();

                if (a > 0)
                {
                    q.push({a, time + n});
                }
            }

            if (!q.empty() && q.front().second == time)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};