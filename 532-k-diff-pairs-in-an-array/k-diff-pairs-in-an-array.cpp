class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0, n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if(k == abs(nums[i]-nums[j])) ans++;
            }
        }
        return ans;
    }
};