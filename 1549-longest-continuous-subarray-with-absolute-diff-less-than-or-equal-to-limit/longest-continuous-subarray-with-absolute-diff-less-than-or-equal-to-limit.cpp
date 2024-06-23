class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int l=0,r=0,ans=1;
        int maxdiff=0;
        priority_queue<vector<int>> maxi,mini;
        while( r<n){
            while(r<n)
                {
                
                maxi.push({ nums[r],r });
                mini.push({-nums[r],r });
                maxdiff= abs( maxi.top()[0]+mini.top()[0]);
                if(maxdiff>limit) break;
                r++;
                ans=max(ans,r-l);
            }
            
            while(maxdiff>limit && l<r){
                l++;
                while( maxi.top()[1]<l ) maxi.pop();
                while( mini.top()[1]<l ) mini.pop();
                maxdiff= abs( maxi.top()[0]+mini.top()[0]);
            }
        }
        return ans;
    }
};

// 10 1 2 4 7 2
// 10,1 
// 1,10