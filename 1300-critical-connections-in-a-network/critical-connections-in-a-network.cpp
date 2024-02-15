class Solution {
public:
    int rec(int i, int p, int k, vector<int>& rank, vector<int>& vis, vector<vector<int>>& adj,vector<vector<int>>& ans){
        rank[i]=k;
        int mindepth=INT_MAX;
        vis[i]=1;
        for(auto it:adj[i]){
            if(it!=p){
                if(vis[it]){
                    mindepth=min(mindepth,rank[it]);
                }
                else{
                    int minrank=rec(it,i,k+1,rank,vis,adj,ans);
                    if(rank[i]<minrank){
                        if(i<it) ans.push_back({i,it});
                        else ans.push_back({it,i});
                    }
                    mindepth=min(minrank,mindepth);
                }
            }
        }
        return mindepth;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans,adj(n);
        vector<int> rank(n,-1),vis(n,0);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        rec(0,-1,0,rank,vis,adj,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};