class Solution {
public:
    int f(int n,vector<int>&dp){
        // there is only 1 ways if you go to 1 from 0 but no way to go 1 from -1 or any val less than 0
        if(n==0) return 1;
        if(n<0) return 0; 
        if(dp[n]!=-1)return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    int climbStairs(int n) {
     vector<int>dp(n+1,-1);
     return f(n,dp);
    }
};
