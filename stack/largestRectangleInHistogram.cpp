class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<pair<int, int>> st;
        int a;
        int mx = 0;
        int ar;
        for (int i = 0; i < heights.size(); i++)
        {
            a = i;
            while (!st.empty() && heights[i] < st.top().second)
            {
                a = st.top().first;
                ar = st.top().second * (i - a);
                if (ar > mx)
                {
                    mx = ar;
                }
                st.pop();
            }
            st.push({a, heights[i]});
        }
        while (!st.empty())
        {
            a = st.top().first;
            ar = st.top().second * (heights.size() - a);
            if (ar > mx)
            {
                mx = ar;
            }
            st.pop();
        }
        return mx;
    }
};