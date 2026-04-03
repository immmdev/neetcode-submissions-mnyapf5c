class Solution {
public:
    string normalize(string &s){
        string n="";
        for(int i=0; i<s.size(); i++){
            if(isalnum(s[i]) && s[i]!=' ') n+=tolower(s[i]);
        }
        return n;
    }
    bool isPalindrome(string s) {
        s=normalize(s);
        int n=s.size();
        int i=0; 
        int j=n-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
