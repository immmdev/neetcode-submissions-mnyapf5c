class Solution {
public:
    map<char,string>f;
    string s="";
    string encode(vector<string>& strs) {
        char index='a';
        for(int i=0; i<strs.size(); i++){
            f[index]=strs[i];
            s+=index;
            index=index+1;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>res;
        for(int i=0; i<s.size(); i++){
            res.push_back(f[s[i]]);
        }
        return res;
    }
};













