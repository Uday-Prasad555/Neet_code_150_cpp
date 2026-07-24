class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> freqMap;
        int l = 0;
        int r = 0;
        int sol = 0;
        int maxi = 0;
        int freq;
        while (r < s.size())
        {
            freqMap[s[r]]++;
            for (auto &it : freqMap)
            {
                maxi = max(maxi, it.second);
            }
            while (r - l + 1 - maxi > k)
            {
                freqMap[s[l]]--;
                l++;
            }
            sol = max(sol, r - l + 1);
            r++;
        }
        return sol;
    }
};