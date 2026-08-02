class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>c;
        for(int i=0; i<n; i++){
           int compliment=target-nums[i];
           if(c.find(compliment)!=c.end()) return {c[compliment],i};
           c[nums[i]]=i;
        }
        return {};
    }
};
