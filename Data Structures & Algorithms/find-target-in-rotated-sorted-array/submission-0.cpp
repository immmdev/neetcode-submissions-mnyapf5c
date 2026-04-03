class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        // one part of array will always be sorted around mid
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==target){
                return m;
                break;
            }
            // check if left is sorted 
            if(nums[l]<=nums[m]){
                // now check if it lies in this range or not
                if(target>=nums[l] && target<=nums[m]) h=m-1;
                else l=m+1;

            // if not right then left will be sorted
            } else {
                // check if lies in the range
                if(target>=nums[m] && target<=nums[h]) l=m+1;
                else h=m-1;
            }
        }
        return -1;
    }
};
