class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(ans.size()>0) break;
            for(int j=i+1; j<n; j++){
                if(ans.size()>0) break;
                if(nums[i]+nums[j]==target) {
                ans.push_back(i);
                ans.push_back(j);
                break;
                }
            }
        }
        return ans;
    }
};
