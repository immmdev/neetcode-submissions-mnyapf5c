class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i]==nums[i-1])continue;
            int t=-nums[i];
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[j]+nums[k];
                if(sum==t) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;
                    k--;
                }
                else if(sum>t) k--;
                else j++;
            }
        }
        return ans;
    }
};