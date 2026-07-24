class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> sol;
        deque <int> qu;
        int r=0;
        int l=0;
        while (r<nums.size()){
            while(!qu.empty() && nums[qu.back()]<=nums[r]){
                qu.pop_back();
            }
            qu.push_back(r);
            if(l>qu[0]){
                qu.pop_front();
            }
            if(r+1>=k){
                sol.push_back(nums[qu[0]]);
                l++;
            }
            r++;
        }
        return sol;
    }
};