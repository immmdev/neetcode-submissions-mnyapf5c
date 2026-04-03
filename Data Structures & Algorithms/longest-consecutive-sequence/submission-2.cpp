class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        map<int,int>f;
        for(int i=0; i<nums.size(); i++){
            f[nums[i]]++;
        }
        int maxLen=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int cnt=1;
            if(f.find(nums[i]-1)==f.end()){
                int j=1;
                while(f.find(nums[i] + j) != f.end()){
                    cnt++;
                    j++;
                }
                maxLen=max(maxLen,cnt);
            }
           
        }
        return maxLen;
    }
};
