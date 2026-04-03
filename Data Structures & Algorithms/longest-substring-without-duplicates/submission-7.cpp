class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        set<int>st;
        int ml=0;
        int i=0;

        for(int j=0; j<n; j++){
            // remove all the elements untill the dupe repeated get removed 
            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            // start from there again
            st.insert(s[j]);
            // calculating continuous length
            ml=max(ml,j-i+1);
        }
        
     return ml;

    }
};
