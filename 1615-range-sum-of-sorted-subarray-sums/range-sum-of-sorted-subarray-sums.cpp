class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        vector<long long> sub;
        int mod  = 1e9 + 7;
        for(int i=0;i<n;i++){
            long long sum = 0;
            for(int j = i ; j<n ; j++){
                sum= (sum+ nums[j]);
                sub.push_back(sum);
            }
        }
        sort(sub.begin() , sub.end());
        int ans = 0;
        for(int i = l-1; i <r ; i++){
            ans = (ans+sub[i])%mod;
        }
        return ans;
        
    }
};