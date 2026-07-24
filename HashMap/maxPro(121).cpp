class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int l = 0;
        int r = 1;
        int maxi = 0;

        while (r < prices.size())
        {

            if (prices[r] > prices[l])
            {
                int curr = prices[r] - prices[l];
                maxi = max(maxi, curr);
            }
            else
            {
                l = r;
            }

            r++;
        }

        return maxi;
    }
};