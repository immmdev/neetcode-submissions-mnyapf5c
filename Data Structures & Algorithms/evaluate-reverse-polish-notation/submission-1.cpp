class Solution {
    
public:
    int operate(int o1,int o2,string op){
        if(op=="+"){
            return o1+o2;
        }
        else if(op=="*"){
            return o1*o2;
        }
        else if(op=="/"){
            return o1/o2;
        }
        else if(op=="-"){
            return o1-o2;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0; i<n; i++){
            if(tokens[i]=="*" || tokens[i]=="/" || tokens[i]=="-" || tokens[i]=="+"){
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(operate(n2,n1,tokens[i]));
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
