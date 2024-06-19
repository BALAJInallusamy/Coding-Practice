class Solution {
public:
    int findCircleNum(vector<vector<int>>& iscon) {
        int n=iscon.size();
        vector<vector<int>> graph(n );
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(iscon[i][j]) graph[i].push_back(j),graph[j].push_back(i);
            }
        }
        stack<int> st;
        vector<int> vis(n);
        int ans=0;
        for(int i=0;i<n;i++){

            if(vis[i]==0){
                vis[i]=1;
                ans++;
                st.push(i);
                while(!st.empty()){
                    int temp=st.top();
                    st.pop();
                    vis[temp]=1;
                    for(auto it:graph[temp]){
                        if(vis[it]==0) st.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
        return ans;
    }
};