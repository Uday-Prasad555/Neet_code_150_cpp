class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int max = 0;
        unordered_set<int> us;
        for (int i = 0; i < nums.size(); i++)
        {
            us.insert(nums[i]);
        }
        for (int num : us)
        {
            int c = 0;
            if (us.find(num - 1) == us.end())
            {
                c = c + 1;
                while (us.find(num + c) != us.end())
                {
                    c = c + 1;
                }
                if (c > max)
                {
                    max = c;
                }
            }
        }
        return max;
    }
};