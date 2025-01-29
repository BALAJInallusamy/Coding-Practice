class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] ==2) q.push({i,j,0});
            }
        }
        int ans = 0;
        while(q.size()){
            vector<int> d = {-1,0,1,0,-1};
            for(int i = 0 ;i< q.size() ; i++){
                auto x = q.front()[0],y = q.front()[1],t = q.front()[2];
                q.pop();
                grid[x][y] = 0;
                ans = t;
                // cout<<x<<","<<y<<":"<<t<<" ";
                for(int j = 0 ; j< 4 ; j++){
                    int dx = d[j] + x , dy = d[j+1] +y;
                    if(dx>=0 && dx<m && dy>=0 && dy<n && grid[dx][dy] == 1){
                        q.push({dx,dy,t+1});
                        grid[dx][dy] =0;
                    }
                }
            }
        }
        for(auto it: grid){
            for(auto x : it) if(x==1) return -1;
        }
        return ans;
    }
};
// 2 2
// 2 2
// 0 0
// 2 0