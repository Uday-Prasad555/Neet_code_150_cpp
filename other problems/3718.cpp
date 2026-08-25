class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int m = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == k * m)
            {
                m = m + 1;
            }
        }
        return k * m;
    }
};