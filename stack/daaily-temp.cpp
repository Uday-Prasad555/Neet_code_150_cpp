class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<pair<int, int>> st;
        int diff;
        vector<int> sol(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!st.empty() && temperatures[i] > st.top().first)
            {
                diff = i - st.top().second;
                sol[st.top().second] = diff;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return sol;
    }
};