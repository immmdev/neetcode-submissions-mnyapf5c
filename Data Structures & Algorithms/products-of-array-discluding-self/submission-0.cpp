class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p=1;
        int isZero=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0) p*=nums[i];
            else isZero++;
        }
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            if(isZero==1){
                if(nums[i]==0) ans.push_back(p);
                else ans.push_back(0);
            }
            else if(isZero>1){
                ans.push_back(0);
            } 

            else ans.push_back(p/nums[i]);
        }
        return ans;
    }
};
