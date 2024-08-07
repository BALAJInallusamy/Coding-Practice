class Solution {
public:

    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n=nums.size();
        vector<int> hash(1001);
        queue<int> q;
        q.push(start);
        int ans = 0;
        while(q.size()){
            int m = q.size();

            for(int k=0 ; k< m ; k++){
                int top = q.front();
                if(top == goal) return ans;
                q.pop();
                for(int i = 0 ;i<n ; i++){
                    long long x = top^nums[i];

                    if(top - nums[i] == goal || top + nums[i] == goal || x == goal) return ans+1;
                    
                    if( top-nums[i]>=0 && top-nums[i]<=1000 && hash[top - nums[i]] != 1 ){
                        q.push(top-nums[i]);
                        hash[top - nums[i]] = 1;
                    }
                    if( top+nums[i]>=0 && top+nums[i]<=1000 && hash[top + nums[i]] != 1 ){
                        q.push(top+nums[i]);
                        hash[top + nums[i]] = 1;

                    }
                    if( (x) >=0 && (x)<=1000 && hash[x] != 1 ){
                        q.push(top^nums[i]);
                        hash[top ^ nums[i]] = 1;
                    }
                }
            }
            ans++;
            
        }
        return -1;

    }
};