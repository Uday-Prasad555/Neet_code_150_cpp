class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> sol;
        int p = 1;
        int q = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                p = p * 1;
            }
            else
            {
                p = p * nums[i - 1];
            }
            sol.push_back(p);
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (i == nums.size() - 1)
            {
                q = q * 1;
            }
            else
            {
                q = q * nums[i + 1];
            }
            sol[i] = sol[i] * q;
        }
        return sol;
    }
};