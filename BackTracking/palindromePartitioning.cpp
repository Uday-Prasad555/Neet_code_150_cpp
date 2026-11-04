class Solution
{
public:
    bool isPalindrome(string s, int i, int j)
    {
        while (j > i)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> curr;
        vector<vector<string>> sol;
        auto bk = [&](auto &&self, int i) -> void
        {
            if (i == s.size())
            {
                sol.push_back(curr);
                return;
            }
            for (int j = i; j < s.size(); j++)
            {
                if (isPalindrome(s, i, j))
                {
                    curr.push_back(s.substr(i, j - i + 1));
                    self(self, j + 1);
                    curr.pop_back();
                }
            }
        };
        bk(bk, 0);
        return sol;
    }
};
