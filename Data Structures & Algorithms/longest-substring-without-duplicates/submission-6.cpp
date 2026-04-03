class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        set<int>st;
        int l=0;
        int ml=0;
        int i=0;
        for(int j=0; j<n; j++){
            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            ml=max(ml,j-i+1);
        }
        
     return ml;

    }
};
