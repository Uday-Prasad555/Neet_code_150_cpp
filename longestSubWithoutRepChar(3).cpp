class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0;
        int sol = 0;
        unordered_set<char> us;
        for (int r = 0; r < s.size(); r++)
        {
            while (us.count(s[r]))
            {
                us.erase(s[l]);
                l++;
            }
            us.insert(s[r]);
            sol = max(sol, r - l + 1);
        }
        return sol;
    }
};