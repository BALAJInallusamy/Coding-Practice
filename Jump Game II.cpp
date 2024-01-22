class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]=max(nums[i]+i,nums[i-1]);
        }
        int ans=0;
        for(int i=0;i<n-1;){
            i=nums[i];
            ans++;
        }
        return ans;
    }
};
