class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t == "")
        {
            return "";
        }
        if (t.size() > s.size())
        {
            return "";
        }
        unordered_map<char, int> countT, window;
        for (int i = 0; i < t.size(); i++)
        {
            countT[t[i]]++;
        }
        int have = 0;
        int need = countT.size();
        int res[2] = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;
        for (int r = 0; r < s.size(); r++)
        {
            window[s[r]] = window[s[r]] + 1;
            if (countT[s[r]] != 0 && window[s[r]] == countT[s[r]])
            {
                have = have + 1;
                while (have == need)
                {
                    if (r - l + 1 < resLen)
                    {
                        res[0] = l;
                        res[1] = r;
                        resLen = r - l + 1;
                    }
                    window[s[l]] -= 1;
                    if (countT[s[l]] != 0 && countT[s[l]] > window[s[l]])
                    {
                        have -= 1;
                    }
                    l += 1;
                }
            }
        }
        if (res[0] == -1)
        {
            return "";
        }
        int start = res[0];
        int end = res[1];
        return s.substr(start, end - start + 1);
    }
};