class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(), ans=0, count=0;
        unordered_map<int,int> pre; 
        pre[0]=-1;
        for(int i=0;i<n;i++){
           count += nums[i]==1 ? 1 : -1;
           if(pre.count(count)) ans=max(ans,i-pre[count]);
           else pre[count]=i;
        }
        
        return ans;
    }
};

