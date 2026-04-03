class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]==nums[i])cnt++;
        }
        if(cnt>=1) return true;
        return false;
    }
};