class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int l=n-1;
        while(l>0){
            while(nums[l-1] == nums[l]){
                l--;
                if(l==0) return ans+= nums[l]==0 ? 1:0 ;
            }
            ans++;
            l--;
  
        }
        if(nums[l]==0 ) ans++;
        return ans;
    }
};

// 111 10 0001
//      1
// 1000 01 111
//      2
// 0111 10 000
//  2     1            