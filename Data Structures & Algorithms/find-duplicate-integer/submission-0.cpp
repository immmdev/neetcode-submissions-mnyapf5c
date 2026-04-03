class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>f;
        for(int i=0; i<nums.size(); i++){
            if(f.find(nums[i])!=f.end()) return nums[i];
            else f[nums[i]]++;
        }
        return -1;
    }
};
