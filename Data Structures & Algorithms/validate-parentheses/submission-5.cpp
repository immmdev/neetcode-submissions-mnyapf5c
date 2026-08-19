class Solution {
public:
    bool isValid(string s) {
        map<char,char>f;
        
        f['}']='{';
        f[']']='[';
        f[')']='(';

        int n=s.size();
        stack<char>st;
        for(int i=0; i<n; i++){
            if(st.size()>0 && st.top()==f[s[i]])st.pop();
            else st.push(s[i]);
        }
        if(st.size()==0) return true;
        return false;
    }
};
