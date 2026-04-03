class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=prices[0];
        int prof=0;
        int n=prices.size();
        for(int i=1; i<n; i++){
            if(prices[i]<p) p=prices[i];
            else prof=max(prof,prices[i]-p);
        }
        return prof;
    }
};
