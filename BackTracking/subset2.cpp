class Solution
{
public:
    vector<vector<int>> sol;
    void bk(vector<int> &nums, vector<int> &curr, int i)
    {
        if (i == nums.size())
        {
            sol.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        bk(nums, curr, i + 1);
        curr.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
        {
            i++;
        }
        bk(nums, curr, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        bk(nums, curr, 0);
        return sol;
    }
};