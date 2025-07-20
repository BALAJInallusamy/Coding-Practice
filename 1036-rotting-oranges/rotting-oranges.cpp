class Solution {
public:
    vector<int> d = {-1,0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size(), m = grid[0].size();
        queue<vector<int>> q,fresh;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
                if(grid[i][j] == 1){
                    fresh.push({i,j});
                }
            }
        }
        int ans = 0;
        while(q.size()){
            int x = q.front()[0], y = q.front()[1], t = q.front()[2];
            q.pop();
            for(int k=0; k< 4 ; k++){
                int dx= d[k] + x , dy = d[k+1] + y;
                if(dx<n && dx>=0 && dy<m && dy>=0 && grid[dx][dy] == 1){
                    q.push({dx,dy,t+1});
                    grid[dx][dy] = 2;
                    ans = max(ans,t+1);
                }
            }
        }
        // for(int i = 0 ; i< n ; i++){
        //     for(int j = 0; j < m ; j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        while(fresh.size()){
            int x = fresh.front()[0], y = fresh.front()[1];
            fresh.pop();
            if(grid[x][y] == 1) return -1;
        }
        return ans;
    }
};