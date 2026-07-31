class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int c = 0;
        int a;
        for (int i = 0; i < nums.size(); i++)
        {
            if (c == 0)
            {
                c = 1;
                a = nums[i];
            }
            else if (nums[i] == a)
            {
                c++;
            }
            else
            {
                c--;
            }
        }
        return a;
    }
};