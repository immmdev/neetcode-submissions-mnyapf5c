class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;

        vector<int> w1(26, 0), w2(26, 0);

        // freq of s1
        for (int i = 0; i < n; i++) {
            w1[s1[i] - 'a']++;
        }

        int k = 0, j = n - 1;

        // first window
        for (int i = k; i <= j; i++) {
            w2[s2[i] - 'a']++;
        }

        while (j < m) {
            if (w1 == w2) return true;
    
            w2[s2[k] - 'a']--;  
            k++;
            j++;

            if (j < m)
                w2[s2[j] - 'a']++; 
        }

        return false;
    }
};