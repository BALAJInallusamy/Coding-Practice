class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size(),ans=0;
        vector<int> nums(n);
        for(int i=1;i<n;i++){
            if(colors[i]!=colors[i-1]){
                nums[i]+=nums[i-1]+1;
            }
        }
        
        for(int i=0;i<k;i++){
            if(i==0){
                if(colors[i]!=colors[n-1]){
                nums[i]+=nums[n-1]+1;
                }
            }
            else{
                if(colors[i]!=colors[i-1]){
                nums[i]=nums[i-1]+1;
                }
            }
        }
        for(auto it:nums) {
           // cout<<it<<" ";
            if(it>=k-1) ans++;
        }
        return ans;
    }
};