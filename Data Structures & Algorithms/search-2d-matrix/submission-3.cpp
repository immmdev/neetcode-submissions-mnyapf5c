class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int lr=0,lc=0;
        int hr=0,hc=m-1;

        while(lr<n && hr<n){
            if(matrix[lr][lc] <= target && target <= matrix[hr][hc]){

                if(matrix[lr][lc]==target || target==matrix[hr][hc]) return true;

                while(lc<=hc){
                    int mid=(lc+hc)/2;
                    if(matrix[lr][mid]==target) return true;
                    else if(matrix[lr][mid]>target) {
                        hc=mid-1;
                    } else {
                        lc=mid+1;
                    }
                }
            } 
            lr++;
            hr++;
        }
        return false;
    }
};
