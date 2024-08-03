typedef vector<int> vec;
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1e9));
        if( grid[0][1]>1 && grid[1][0]>1) return -1;
        dp[0][0] = 0;
        vec xy = {-1,0,1,0,-1};

        priority_queue<vec,vector<vec>, greater<vec>> pq;
        pq.push({0,0,0});
        while(pq.size()){
            vec top = pq.top();
            int i = top[1], j = top[2];
            int time = top[0];
            pq.pop();
            for(int k = 0 ; k< 4 ;k ++){
                int x = xy[k] + i, y = xy[k+1] + j;

                if( x >= m || y >= n || x<0 || y < 0 ) continue;
                int d = time +1;
                while(d<grid[x][y]) d += 2;
                if( dp[x][y] > d) {

                    dp[x][y] = d;
                    pq.push({d,x,y});
                }

            }
        }
        // for(auto it:dp){
        //     for(auto x:it) cout<<x<<" ";cout<<endl;
        // }
        return dp[m-1][n-1];
    }
};