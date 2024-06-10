class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int mid= lower_bound(nums.begin(), nums.end(), 0)- nums.begin(), n= nums.size();
        int l,r=mid;
        l=mid-1;
        vector<int> ans;
        while(l>-1 && r<n){
            if((-nums[l]) < nums[r] ) ans.push_back(nums[l]*nums[l]), l--;
            else ans.push_back(nums[r]*nums[r]), r++;
        }
        while(r<n) ans.push_back(nums[r]*nums[r]), r++;
        while(l>-1) ans.push_back(nums[l]*nums[l]), l--;
        return ans;
    }
};