class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int sum = 0;
        for(auto it:nums) sum+=it;
        int n = nums.size();
        int temp = 0;
        for(int i = 0 ; i<n- k ; i++){
            temp+= nums[i];
        }
        int ans = temp;
        for(int i=0;i<k ; i++){
            temp+= -nums[i] + nums[n-k+i];
            ans = min(temp,ans);
        }
        return sum-ans;
    }
};