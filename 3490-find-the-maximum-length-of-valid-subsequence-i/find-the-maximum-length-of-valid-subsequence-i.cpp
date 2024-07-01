class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd=0, even=0, oe=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) even++;
            else odd++;
        }
        int ans=2;
        ans=max(even,odd);
        vector<int> dp(n);
        int flag=0;
        oe=1;
        if(nums[0]%2==0) flag=1;
        for(int i=1;i<n;i++){
            if(nums[i]%2==0 && flag==0) flag=1,oe++;  
            if(nums[i]%2==1 && flag==1) flag=0,oe++;          
        }
        return max(ans,oe);
    }
};
// odd-even = 1
// odd-odd, even,even =0