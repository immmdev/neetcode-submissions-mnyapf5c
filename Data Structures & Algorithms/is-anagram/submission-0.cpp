class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>f1(256);
        for(int i=0; i<s.size(); i++){
            f1[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            f1[t[i]]--;
        }
        for(int i=0; i<256; i++){
            if(f1[i]!=0) return false;
        }
        return true;
    }
};