class MinStack {
public:
    vector<int>v;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        int n=v.size();
        return v[n-1];
    }
    
    int getMin() {
        int minel=INT_MAX;
        for(int i=0; i<v.size(); i++){
            minel=min(minel,v[i]);
        }
        return minel;
    }
};
