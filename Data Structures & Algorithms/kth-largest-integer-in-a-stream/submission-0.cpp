class KthLargest {
public:
    vector<int>kthlargest;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kthlargest=nums;
        kth=k;
        sort(kthlargest.begin(), kthlargest.end());
        
    }
    
    int add(int val) {
        kthlargest.push_back(val);
        sort(kthlargest.begin(), kthlargest.end());
        int n=kthlargest.size();
        return kthlargest[n-kth];
    }
};
