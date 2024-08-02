class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int l =0 , r =0 ;
        int all = accumulate(nums.begin(),nums.end(),0);
        if(all == 0) return 0;
        int n = nums.size();
        int count = accumulate(nums.begin(),nums.begin()+all,0);
        for(int i = 0 ;i<n ; i++) nums.push_back(nums[i]);
        r = all;
        int ans = all - count;
        n *=2;
        while( r<n){
            if( nums[l] == 1 ) {
                count--;
            }
            l++;
            if(nums[r] == 1){
                count++;   
            }
            r++;
            if(all - count == 0) return 0;
            ans = min(ans, all - count);
        }
        return ans;
    }
};

// 1101001
// 100101001
// 