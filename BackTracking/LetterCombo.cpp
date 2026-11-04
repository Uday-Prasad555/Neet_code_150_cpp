class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> hm;
        hm['2'] = "abc";
        hm['3'] = "def";
        hm['4'] = "ghi";
        hm['5'] = "jkl";
        hm['6'] = "mno";
        hm['7'] = "pqrs";
        hm['8'] = "tuv";
        hm['9'] = "wxyz";
        vector<string> sol;
        string s;
        auto bk = [&](auto &&self, int i) -> void
        {
            if (i == digits.size())
            {
                sol.push_back(s);
                return;
            }
            for (int j = 0; j < hm[digits[i]].size(); j++)
            {
                s.push_back(hm[digits[i]][j]);
                self(self, i + 1);
                s.pop_back();
            }
        };
        bk(bk, 0);
        return sol;
    }
};