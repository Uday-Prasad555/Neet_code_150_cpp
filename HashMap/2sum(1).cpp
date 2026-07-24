class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hm;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(hm.count(target-nums[i])){
                return{i,hm[target-nums[i]]};
            }
            hm[nums[i]]=c;
            c++;
        }
        return {};
}};