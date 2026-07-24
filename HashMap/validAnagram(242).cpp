class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> sm, tm;
        for (int i = 0; i < s.size(); i++)
        {
            sm[s[i]]++;
            tm[t[i]]++;
        }
        if (sm == tm)
        {
            return true;
        }
        return false;
    }
};