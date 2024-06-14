class NumMatrix {
public:
    vector<vector<int>> map;
    NumMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(i) mat[i][j]+=mat[i-1][j];
            }
        }
        map=mat;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum= map[row2][col2],
            top=0,side=0,null=0;
        if(row1) top=map[row1-1][col2];
        if(col1) side=map[row2][col1-1];
        if(row1 && col1) null=map[row1-1][col1-1];
        return sum+null-top-side;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */