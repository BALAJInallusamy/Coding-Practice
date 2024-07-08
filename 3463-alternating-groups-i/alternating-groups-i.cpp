class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums) {
        int n= nums.size(), ans=0;
        for(int i=0;i<n;i++){
            if(i>0 && i<n-1){
                if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1]) ans++;
            }
            if(i==0){
                if(nums[i]!=nums[n-1] && nums[i]!=nums[1]) ans++;
            }
            if(i==n-1){
                if(nums[0]!=nums[n-1] && nums[i]!=nums[n-2]) ans++;

            }
        }
        return ans;
    }
};