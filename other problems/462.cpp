class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int mid = nums[nums.size() / 2];

        int count = 0;

        for (int y : nums)
        {
            count += abs(mid - y);
        }

        return count;
    }
};