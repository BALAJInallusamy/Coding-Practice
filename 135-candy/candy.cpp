class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
        if(n == 1) return 1;

        vector<vector<int>> nums(n);

        for(int i = 0 ; i< n ; i++){
            nums[i] = {rat[i],i};
        }
        vector<int> can(n,1);
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i<n ; i++){
            int ind = nums[i][1], val = nums[i][0];

            if(ind == 0){
                if( rat[1] < val )
                can[0] = can[1] + 1; 
                continue;
            }
            if(ind == n-1 ){
                if(rat[n-2] < val)
                can[n-1] = can[n-2] + 1;
                continue;
            }
            
            int pre = ind - 1, next = ind +1;

            if(rat[pre] < val){
                can[ind] = can[pre] + 1;
            }
            if(rat[next] < val){
                can[ind] = max(can[ind] , can[next] + 1);
            }
        }
        int ans =0;
        
         return accumulate(can.begin() , can.end() , 0);
    }
};

// 2 2 1 4
// 1 2 1 2
// 