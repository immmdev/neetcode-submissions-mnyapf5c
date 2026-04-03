class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int cnt=0;
        map<int,int>mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto it: mpp){
            if(it.second>1) {
                return true;
            }
            
        }

        return false;
    }
};