class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // min is always one in coco eating rate
        auto p = minmax_element(piles.begin(), piles.end());
        int l = 1;
        int hi = *p.second;
        int minr=INT_MAX;
        while(l<=hi){
            int r=l+(hi-l)/2;
            long long t=0;
            for(int i=0; i<piles.size(); i++){
               t += (piles[i]+r-1) / r;
            }

            if(t<=h){
                minr=min(minr,r);
                hi=r-1;
                
            } 
            else{
                l=r+1;
            }

        }
        return minr;
    }
};