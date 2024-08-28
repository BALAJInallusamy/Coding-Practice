class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n =grid.size() , m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        vector<int> ds = {1,0,-1,0,1};
        while(pq.size()){
            int i = pq.top()[1], j = pq.top()[2];
            int t = pq.top()[0];
            pq.pop();
            if(i==n-1 && j==m-1) return t;
            for(int k = 0 ; k < 4 ; k++){
                int x = ds[k] + i , y = ds[k+1] +j;
                if(x<n && x>=0 && y<m && y>=0 && grid[x][y]!=-1){
                    pq.push({max(grid[x][y], t) , x , y});
                    grid[x][y] = -1;
                }
            }
        }
        return n*n;
    }
};