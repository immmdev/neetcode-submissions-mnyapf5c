class KthLargest {
public:
    vector<int>kthlargest;
    int k;
    KthLargest(int k, vector<int>& nums) {
        kthlargest=nums;
        this->k=k;
        sort(kthlargest.begin(), kthlargest.end());
        
    }
    
    int add(int val) {
        int n=kthlargest.size();
        // new element make place for it
        kthlargest.resize(n+1);
        int i=n-1;
        // replacing elements till we find correct place for the val
        while(i>=0 && kthlargest[i]>=val){
            kthlargest[i+1]=kthlargest[i];
            i--;
        }
        // found the index that is smaller than val means just after it there is place where we have to set our val i.e. i+1
        kthlargest[i+1]=val;
        return kthlargest[kthlargest.size()-k];
    }
};
