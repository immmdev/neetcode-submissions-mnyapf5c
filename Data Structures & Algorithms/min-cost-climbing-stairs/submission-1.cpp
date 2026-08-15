class Solution {
public:
    int f(int n,vector<int>&cost,vector<int>&dp){
        if(n==0) return cost[0];
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int left=cost[n]+f(n-1,cost,dp);
        int right=cost[n]+f(n-2,cost,dp);
        return dp[n]=min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(f(n-1,cost,dp),f(n-2,cost,dp));
    }
};
