class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int r = nums[0];
        for(int i = 1 ; i < n ; i++){
            if(r < i) return false;
            r = max(r, nums[i] + i);
            if(r == n-1) return 1;
        }
        return 1;
    }
};