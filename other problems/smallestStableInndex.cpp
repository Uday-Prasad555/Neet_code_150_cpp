class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int maxi = -1;
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            mini = min(nums[i], mini);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(maxi, nums[i]);
            if (maxi - mini <= k)
            {
                return i;
            }
            mini = INT_MAX;
            for (int j = i + 1; j < nums.size(); j++)
            {
                mini = min(nums[j], mini);
            }
        }
        return -1;
    }
};