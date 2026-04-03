class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int ans=INT_MAX;
        while(l<=h){
            int mid=(l+h)/2;
            //  checking if the array is already sorted
            if(nums[l]<=nums[h]){
                ans=min(ans,nums[l]);
                break;
            }

            // if not sorted then if mid is grater than low means left array is sorted
            // and rotated as well the min will be at right eliminate left 
            if(nums[mid]>=nums[l]){
                ans=min(ans,nums[l]);
                l=mid+1;

            // else if mid is small this means right is sorted and left become unsorted because
            // then small will be either mid or left of mid hence eliminate right array
            } else {
                ans=min(ans,nums[mid]);
                h=mid-1;
            }
        }
        return ans;
    }
};
