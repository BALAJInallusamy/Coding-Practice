int xy[] = {-1,0,1,0,-1};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int k=2 , ans =0, a=0;
        vector<int> area;
        function<void(int,int)> dfs = [&](int i , int j){
            if( grid[i][j] >1){
                return ;
            }
            if(grid[i][j] == 1){
                a++;
                grid[i][j] = k;
                for( int m=0;m<4;m++){
                    int y = j+ xy[m+1];
                    int x = i+ xy[m];
                    if(x >=0 && y >=0 && x<n && y <n){
                        dfs(x,y);
                    }
                }

            }
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) {
                    a = 0;
                    dfs(i,j);
                    ans = max(ans,a);
                    area.push_back(a);
                    k++;
                    }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //cout<<grid[i][j]<<" ";
                if(grid[i][j] == 0) {
                    int temp =1;
                    unordered_set<int> st;
                    for(int m=0;m<4;m++){
                        int y = j+ xy[m+1];
                        int x = i+ xy[m];

                        if(x >=0 && y >=0 && x<n && y <n && grid[x][y] != 0){
                           st.insert(grid[x][y]-2);                        
                        }
                    }
                    for(auto it:st){
                        temp += area[ it ];
                    }
                    ans = max(ans, temp);
                }
            }
            //cout<<endl;
        }
        return ans;
    }
};