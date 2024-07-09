class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) {
        int n= nums.size(), time =0;
        double ans=0;
        for(int i=0;i<n;i++){
            if(time< nums[i][0]){
                time = nums[i][0];
                ans += nums[i][1] ;
            }
            else{
                ans += time - nums[i][0] + nums[i][1];
            }
            time += nums[i][1];
            //cout<<time<<" "<<ans<<endl;
        }
        return double (ans/n);
    }
};