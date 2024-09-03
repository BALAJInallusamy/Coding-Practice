class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& nums) {

        nums.push_back(bottom -1);
        nums.push_back(top+1);
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0 ;
        for(int i = 1 ; i< n ; i++){
            ans = max(ans, nums[i] - nums[i-1]-1);
        }
        return ans;
    }

};
// 1 4 6 10