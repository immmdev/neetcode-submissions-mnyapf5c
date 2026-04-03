class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>w1;
        if(s1.size()>s2.size()) return false;
        for(int i=0; i<s1.size(); i++){
            w1[s1[i]]++;
        }

        int k=0;
        int j=s1.size()-1;
        for(int m=0; m<=s2.size()-s1.size(); m++){
            unordered_map<char,int>w2;
            for(int l=k; l<=j; l++){
                w2[s2[l]]++;
            }
            if(w1==w2) return true;
            k++;
            j++;
            w2.clear();
        }
        
        return false;
    }
};
