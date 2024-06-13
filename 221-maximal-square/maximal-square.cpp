class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(), m= matrix[0].size();
        vector<vector<int>> sq(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sq[i][j]= matrix[i][j]-'0';
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i>0 && j>0 && sq[i][j]) {
                    sq[i][j]+=min({sq[i][j-1],sq[i-1][j-1],sq[i-1][j]});
                    }
            ans=max(ans,sq[i][j]);

            }
        }   
        return ans*ans;
    }
};