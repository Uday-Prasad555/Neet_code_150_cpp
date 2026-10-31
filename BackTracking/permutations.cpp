class Solution
{
public:
    vector<vector<int>> sol;
    void bk(vector<int> &nums, vector<int> &ds, int freq[])
    {
        if (ds.size() == nums.size())
        {
            sol.push_back(ds);
            return;
        }
        for (int j = 0; j < nums.size(); j++)
        {
            if (!freq[j])
            {
                ds.push_back(nums[j]);
                freq[j] = 1;
                bk(nums, ds, freq);
                ds.pop_back();
                freq[j] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> ds;
        int freq[nums.size()];
        for (int i = 0; i < nums.size(); i++)
        {
            freq[i] = 0;
        }
        bk(nums, ds, freq);
        return sol;
    }
};