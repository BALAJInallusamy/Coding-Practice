class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n,nums[0]%k);
        unordered_map<int,int> st;
        st[0]=-1;
        for(int i=0;i<n;i++) {
            if(i>0) pre[i]=(pre[i-1]+nums[i])%k;
            if( st.find( pre[i] ) != st.end() ) {
                if( (i- st[pre[i]] ) > 1 ) return true;
                }
            else st[pre[i]]=i;
            }
       return false;
    }
};

// 1 2 4 0 1
// 1 3 1 1 2 
// 