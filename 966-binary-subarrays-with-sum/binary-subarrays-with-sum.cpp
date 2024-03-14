class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int n= nums.size(), ans=0, sum=0;
        
        for(int i=0; i< n; i++){
            sum+=nums[i];
            if(sum==goal) ans++;
            if(mp[sum-goal]>0) ans+=mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};