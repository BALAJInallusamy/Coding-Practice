class Solution {
public:
    int set_count(int x){
        int res=0;
        while(x){
            res+=((x)&1);
            x=x>>1;
        }
        return res;
    }
    void sort_part(int i, int j, vector<int>& nums) {
        sort(nums.begin()+i,nums.begin()+j);
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> adj(n,-1);
        
        for(int i=0;i<n;i++) {
            adj[i]=set_count(nums[i]);
        }
        
        for(int i=0;i<n-1;){
            int j=i+1;
            while(j<n && i< n && adj[i]==adj[j]) j++;
            sort_part(i,j,nums);
            i=j;
        }
        
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
};
