int mp[100];
class Solution {
public:
    
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        int ans=0,max=1;
        memset(mp,0,sizeof(mp));

        for( auto it:nums){
            mp[it-1]++;
            if(max==mp[it-1]) ans++;
            if(max<mp[it-1]){
                ans=1;
                max=mp[it-1];
            }
        }
        return ans*max;

    }
};