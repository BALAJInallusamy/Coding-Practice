class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefix(n),suffix(n);
        for(int i=0;i<n;i++){
            prefix[i] += i+1;
            suffix[n-1-i] += (n-i);
            if(i>0) prefix[i]+= prefix[i-1], suffix[n-1-i] += suffix[n-i];
        }
        for(int i=0;i<n;i++){
            if(prefix[i]==suffix[i]) return i+1;
        }
        return -1;
    }
};