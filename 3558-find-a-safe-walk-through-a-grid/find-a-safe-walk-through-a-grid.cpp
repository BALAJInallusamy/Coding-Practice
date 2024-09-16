class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int h) {
        priority_queue<vector<int>> pq;
        int n = grid.size(), m =grid[0].size();
        vector<int> d = {-1,0,1,0,-1};
        pq.push({h - grid[0][0], 0 , 0});
        grid[0][0] = -1;
        while(pq.size()){

            int i = pq.top()[1], j = pq.top()[2] , k = pq.top()[0];
            if(i == n-1 && j == m-1 && k>0) return 1;
            
            pq.pop();

            for(int x = 0 ; x< 4 ; x++){
                int dx = i + d[x], dy = j + d[x+1];
                if(dx >=0 && dy >=0 && dx<n && dy < m && grid[dx][dy]!=-1){
                    pq.push({ k - grid[dx][dy] , dx, dy } );
                    grid[dx][dy] = -1;
                }
            }
        }
        return 0;
    }

    
};