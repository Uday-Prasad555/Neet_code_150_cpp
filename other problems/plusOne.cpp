class Solution
{
public:
    int carry = 0;
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> sol;
        vector<int> rev;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] == 9 && carry == 1)
            {
                rev.push_back(0);
                carry = 1;
            }
            else
            {
                rev.push_back(digits[i] + carry);
                carry = 0;
            }
        }
        if (carry == 1)
        {
            rev.push_back(1);
        }
        for (int j = rev.size() - 1; j >= 0; j--)
        {
            sol.push_back(rev[j]);
        }
        return sol;
    }
};