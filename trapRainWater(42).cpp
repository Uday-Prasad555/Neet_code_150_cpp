class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() == 0)
        {
            return 0;
        }
        int l = 0;
        int r = height.size() - 1;
        int leftmax = height[l];
        int rightmax = height[r];
        int tot = 0;
        while (l < r)
        {
            if (leftmax < rightmax)
            {
                l = l + 1;
                leftmax = max(leftmax, height[l]);
                tot += leftmax - height[l];
            }
            else
            {
                r = r - 1;
                rightmax = max(rightmax, height[r]);
                tot += rightmax - height[r];
            }
        }
        return tot;
    }
};