class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> hm;
        priority_queue<pair<int, int>> pq;
        vector<int> sol;
        for (int i = 0; i < nums.size(); i++)
        {
            hm[nums[i]]++;
        }
        for (auto &p : hm)
        {
            pq.push({p.second, p.first});
        }
        for (int j = 0; j < k; j++)
        {
            sol.push_back(pq.top().second);
            pq.pop();
        }
        return sol;
    }
};