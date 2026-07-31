class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> sol;
        int check = nums.size() / 3;
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
            if (count[nums[i]] == check + 1)
            {
                sol.push_back(nums[i]);
            }
        }
        return sol;
    }
};