class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int res=0;
        int l=0;
        int maxFreq=0;
        vector<int>f(26,0);
        for(int r=0; r<n; r++){
            f[s[r]-'A']++; // storing index of the char
            maxFreq=max(maxFreq,f[s[r]-'A']); // storing max freq of the char in specific window
            // moving to the valid window
            // valid: (window-mostfrequent<=k) else move the left pointer
            while((r-l+1)-maxFreq>k){
                f[s[l]-'A']--;
                l++;
            } 
            // we are here means at valid window
            res=max(r-l+1,res);
        }

        return res;

    }
};
