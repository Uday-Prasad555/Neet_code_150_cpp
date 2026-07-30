class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;
        long long a;
        int mid;
        int ans = r;

        while (l <= r) {
            mid = l + (r - l) / 2;
            a = 0;
            for (int i = 0; i < piles.size(); i++) {
                a += (piles[i] + mid - 1) / mid;
            }

            if (a <= h) {
                ans = mid;
                r = mid - 1;
            }
            else if (a > h) {
                l = mid + 1;
            }
        }
        return ans;
    }
};