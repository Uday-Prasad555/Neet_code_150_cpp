class Solution
{
public:
    vector<vector<int>> sol;
    void bk(vector<int> &nums, int i, vector<int> &curr, int target)
    {

        if (target == 0)
        {
            sol.push_back(curr);
            return;
        }

        for (int j = i; j < nums.size(); j++)
        {

            if (j > i && nums[j] == nums[j - 1])
                continue;
            if (nums[j] > target)
                break;
            curr.push_back(nums[j]);
            bk(nums, j + 1, curr, target - nums[j]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        bk(candidates, 0, curr, target);

        return sol;
    }
};