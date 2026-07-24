class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0;
        int r = height.size() - 1;
        int maxi = 0;

        while (l < r)
        {

            int ar = min(height[l], height[r]) * (r - l);

            if (ar > maxi)
            {
                maxi = ar;
            }

            if (height[l] > height[r])
            {
                r--;
            }
            else
            {
                l++;
            }
        }

        return maxi;
    }
};