class Solution {
public:
// time and space complexity O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // we will maitain an stack at the top of which we contain the latest element for which we dont have the warmer day.
        // as we get the warmer day for the day at the top of the stack we test for the new dya if in the stack else we push the current day in the stack to find warmer day then current we will do it untill resolved for each index and stack id not empty.
        int  n=temperatures.size();
        vector<int>res(n); // store answers
        stack<pair<int,int>>st; // days not resolved {temp,index}
        for(int i=0; i<n; i++){
            int t=temperatures[i]; // current temperature
            while(!st.empty() && t>st.top().first){ // loop until you have some el that as current day as warmer day.
                auto node=st.top();
                st.pop();
                res[node.second]=i-node.second;
            }
            st.push({t,i}); // push the current element in the stack as unresolved.
        }
        return res;
    }
};