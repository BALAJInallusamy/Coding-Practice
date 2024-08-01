class Solution {
public:

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat ( 3*n,vector<int> (3*n) );
        
        function<void(int, int )> one = [&] (int i , int j){
            mat[3*i][3*j+2]=1;
            mat[3*i+1][3*j+1]=1;
            mat[3*i+2][3*j]=1;
        } ;
        function<void(int, int )> two = [&] (int i , int j){
            mat[3*i][3*j]=1;
            mat[3*i+1][3*j+1]=1;
            mat[3*i+2][3*j+2]=1;
        } ;
        
        int k =2;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0; j < grid[i].size() ; j++){
                if(grid[i][j] == '/'){
                    one(i,j);
                }
                else if( grid[i][j] == ' ') {
                    continue;
                }
                else{
                    two(i,j);
                }
            }
        }

        queue<vector<int>> q;
        vector<int> d = {-1,0,1,0,-1};
        auto rec = [&] {
            while(q.size()){
                vector<int> top = q.front();
                q.pop();
                mat[top[0]][top[1]] = k;
                for(int i = 0; i<4; i++ ){
                    int x = d[i] + top[0];
                    int y = d[i+1] + top[1];
                    if(x>=0 && y>=0 && x<3*n && y<3*n && mat[x][y] == 0){
                        mat[x][y] = k;
                        q.push({x,y});
                    }
                }
            }
        };
        //cout<<mat.size()<<mat[0].size()<<endl;
        for(int i =0 ; i < 3*n ; i++){
            for(int j = 0 ; j< 3*n ; j++){
                if(mat[i][j] == 0){
                    q.push( {i,j} );
                    rec();
                    k++;
                }
            }
        }
        // for(auto it:mat){
        //     for (auto x:it) cout<<x<<" ";cout<<endl;
        // }

        return k-2;
    }
};