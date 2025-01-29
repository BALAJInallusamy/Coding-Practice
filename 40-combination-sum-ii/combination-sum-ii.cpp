class Solution {
public:
vector<vector<int>> ans;
    void rec(int i, vector<int>& nums, int n, int tar , vector<int> ds){
        if(tar <=0 ) {
            ans.push_back(ds);
            return;
        }
        if(i == n) return;
        int j = i+1;
        while(j<n && nums[i] == nums[j]) j++;
        rec(j, nums, n , tar, ds);
        if(nums[i]<= tar ) {
            ds.push_back(nums[i]);
            rec(i+1, nums,n, tar - nums[i] , ds);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) {
        sort(nums.begin(),nums.end());
        rec(0 , nums, nums.size(), tar, {});
        return ans;
    }
};