class Solution {
public:
    int rec(int i,vector<int>& hash, vector<int>&nums,unordered_map<int,int> &st){
        if(hash[i]>1) return hash[i];
        
        if(st.find(nums[i]+1)==st.end()) return hash[i];
        else{
            hash[i]=1+rec(st[nums[i]+1],hash,nums,st);
        }
        return hash[i];
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> st;
        int n=nums.size();
        vector<int> hash(n,1);
        int ans=0;
        for(int i=0;i<n;i++) st[nums[i]]=i;
        for(int i=0;i<n;i++){
            ans=max(ans,rec(i,hash,nums,st));
        }
        return ans;
    }
};