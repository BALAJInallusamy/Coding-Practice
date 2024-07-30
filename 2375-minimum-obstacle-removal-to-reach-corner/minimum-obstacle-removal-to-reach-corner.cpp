typedef vector<int> pp;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> xy = {-1,0,1,0,-1};

        
        vector<vector<int>> vis (n,vector<int>(m,1e6));
        vis[0][0] = 0;
        
        priority_queue< pp,vector<pp>, greater<pp> > pq;
        pq.push({0,0,0});
        while(pq.size()){
            int d = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            for(int k = 0 ; k<4 ; k++){
                int x= xy[k]+i, y =xy[k+1]+j;

                if(x>=0 && x<n && y>=0 && y<m){
                    
                    if( grid[x][y] ==1 && vis[x][y]> d+1){
                        pq.push({d+1,x,y});
                        vis[x][y] = d+1;
                    }
                    if(grid[x][y] ==0 && vis[x][y] > d){
                        pq.push({d,x,y});
                        vis[x][y] = d;
                    }
                    
                }
            }
        }
        // for(auto it:vis){
        //     for(auto x : it) cout<<x<<" ";cout<<endl;
        // }
        return vis[n-1][m-1];
    }
};