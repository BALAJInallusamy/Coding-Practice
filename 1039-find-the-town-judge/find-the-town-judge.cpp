class Solution {
public:
    int arr[1001],nums[1001];
    int findJudge(int n, vector<vector<int>>& trust) {
        memset(arr,0,sizeof(arr));
        for(auto it:trust) arr[it[0]]++,nums[it[1]]++;
        int ans=-1;
        
        for(int i=1;i<=n;i++){
            if(arr[i]==0 && nums[i]==n-1) {
                ans=i;
                break;
            }

        }
        return ans;
    }
};