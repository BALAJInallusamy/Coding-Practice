class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size(), l= 0 , r = n-1;
        // while(nums[l] <=0 ) l++;
        // while(nums[r] <=0 ) r--;
        // int ans = 0;
        // while(l<=r){
        //     ans+= (r-l+1)*min(nums[r],nums[l]);
        //     if(nums[l]<nums[r]) l++;
        //     else r--;
        // }
        for(int i = 0 ;i<n ; i++){
            if(nums[l]<nums[i]) l=i;
            if(nums[r]<nums[n-1-i]) r= n-1-i;
        }
        int last = 0, ans=0;
        for(int i = 0 ; i< l ; i++){
            if(nums[i]>last) last = nums[i];
            ans+= last;
            // cout<<last<<" ";
        }
        last = 0;
        for(int i = n-1 ; i>r ; i--){
            if(nums[i]>last) last = nums[i];
            ans+= last;
            // cout<<last<<" ";

        }
        if(l!=r) ans+= nums[l]*(r-l-1) ;
        for(int i = 0 ; i< n ; i++){
            if(i==l || i == r) continue;
            ans-=nums[i];
        }
        
        return ans;
    }
};