class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxarea=INT_MIN;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                maxarea=max(maxarea,min(heights[i],heights[j])*abs(i-j));
            }
        }

        // int i=0;
        // int j=n-1;
        // while(i<j){
        //     int a=min(heights[i],heights[j])*abs(i-j);
        //     maxarea=max(maxarea,a);
        //     i++;
        //     j--;
        // }
        return maxarea;
    }
};
