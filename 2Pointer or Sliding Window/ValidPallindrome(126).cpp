class Solution
{
public:
    bool isPalindrome(string s)
    {
        string og = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (!isalnum(s[i]))
                continue;
            og += tolower(s[i]);
        }
        int in = 0;
        int fi = og.size() - 1;
        while (in <= fi)
        {
            if (og[in] != og[fi])
            {
                return false;
            }
            in = in + 1;
            fi = fi - 1;
        }
        return true;
    }
};