class Solution {
public:
      int f(int i,vector<int>& nums,vector<int>&dp,int l){
        if(i<l)return 0;
        if(dp[i]!=-1)return dp[i];
        int notpick=0+f(i-1,nums,dp,l);
        int pick=nums[i]+f(i-2,nums,dp,l);
        return dp[i]=max(notpick,pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        vector<int>dp1(n+1,-1);
        if(n==1)return nums[0];
        return max(f(n-1,nums,dp,1),f(n-2,nums,dp1,0));
    }
};
