class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int in = 0;
        int fi = numbers.size() - 1;
        while (in < fi)
        {
            if (numbers[in] + numbers[fi] == target)
            {
                return {in + 1, fi + 1};
            }
            if (numbers[in] + numbers[fi] > target)
            {
                fi = fi - 1;
            }
            if (numbers[in] + numbers[fi] < target)
            {
                in = in + 1;
            }
        }
        return {};
    }
};