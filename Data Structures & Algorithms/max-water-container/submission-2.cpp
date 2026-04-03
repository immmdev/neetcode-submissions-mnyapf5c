class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxarea=INT_MIN;
        int i=0; 
        int j=n-1;
        while(i<j){
            maxarea=max(maxarea,min(heights[i],heights[j])*abs(i-j));
            if(heights[i]>heights[j]) j--;
            else if(heights[i]<heights[j]) i++;
            else i++;   
        }
        return maxarea;
    }
};
