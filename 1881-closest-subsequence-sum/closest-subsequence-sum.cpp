class Solution {
public:
    
    vector<int> find(int l , int r , vector<int>& nums){
        if(l> r) return {0};
        int  n= r- l +1 ;
        int mask = (1<<n )-1;
        vector<int> ans(1,0);
        for(int i =1 ; i<= mask ; i++){

            int sum = 0;
            
            for(int k = 0 ; k < n ; k++){
                if(( i & (1<<k) )!= 0 ) sum+= nums[k+l];
            }
            
            ans.push_back(sum);
        }
        return ans;
    }

    int rec(int l , int r , vector<int>& nums, int k){
        int mid = (l+r)/2;
        vector<int> first, second;
        first = find(l, mid,nums);

        sort(first.begin(),first.end());

        second = find(mid+1,r,nums);

        int n = second.size();
        int ans=INT_MAX;
        
        for(int i=0;i<second.size();i++){
            int s=second[i];
            int l=0;
            int r=first.size()-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                int sum=s+first[mid];
                if(sum==k)
                    return 0;
                ans=min(ans,abs(sum-k));
                if(sum>k){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }    
            }
        }
        
        return ans;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return rec(0, n-1, nums , goal);
    }
};