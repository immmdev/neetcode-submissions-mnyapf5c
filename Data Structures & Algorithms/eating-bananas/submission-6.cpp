class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        auto p=minmax_element(piles.begin(),piles.end());
        int hi=*p.second;
        int minr=INT_MAX;
        // we are here doing binary search on answers
        // the rate will lie between 1 and max of the piles array

        while(l<=hi){
            int k=l+(hi-l)/2;
            long long t=0;
            for(int i=0; i<piles.size(); i++){
                // ceil(a/b)=a+b-1/b but here this is integer division ceil method will not work
                // t+=ceil((double)piles[i]/k); option
                t+=(piles[i]+k-1)/k;
            }
            // try smaller rate 
            if(t<=h){
                minr=min(minr,k);
                hi=k-1;
            } else l=k+1;
        }
        return minr;
    }
};