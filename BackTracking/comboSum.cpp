class Solution
{
public:
    vector<vector<int>> sol;

    void bk(vector<int> &ind, int i, vector<int> &curr, int target)
    {

        if (target == 0)
        {
            sol.push_back(curr);
            return;
        }
        if (i >= ind.size() || target < 0)
        {
            return;
        }
        curr.push_back(ind[i]);
        bk(ind, i, curr, target - ind[i]);
        curr.pop_back();
        bk(ind, i + 1, curr, target);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> curr;
        bk(candidates, 0, curr, target);
        return sol;
    }
};