vector<int> xy={-1,0,1,0,-1};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m= board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        stack<vector<int>> st;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && vis[i][j]==0 && board[i][j]=='O'){

                    st.push({i,j});
                    while(!st.empty()){
                        vector<int> top=st.top();
                        st.pop();
                        vis[top[0]][top[1]]=1;
                        for(int k=0;k<4;k++){
                            int nr=top[0]+xy[k], nc= top[1] + xy[k+1];
                            if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='O' && vis[nr][nc]==0){
                                st.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(vis[i][j]==0 && board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};