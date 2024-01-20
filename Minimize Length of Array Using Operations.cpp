class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int n=nums.size(), count=0, mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(nums[i],mini);
        }
        for(auto it:nums){
            count+=(mini==it)?1:0;
            if(it%mini!=0) return 1;
        }
        int ans= count/2+count%2;
        return ans;
    }
};
