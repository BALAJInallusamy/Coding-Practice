class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        queue<int> q;
        vector<vector<int>> path(n);
        for(auto it:edges){
            path[it[0]].push_back(it[1]);
            path[it[1]].push_back(it[0]);
        }
        int ans = 1e9;
        for(int i= 0 ; i< n ; i++){
            
            vector<int> vis(n,-1);
            vector<int> parent(n,-1);
            
            vis[i] = 0;
            q.push(i);

            while(q.size()){
                int node = q.front();
                q.pop();

                for(auto it: path[node]){
                    if(vis[it]!= -1){
                        if(parent[node] != it)  ans = min(ans, vis[it] + vis[node] + 1);
                    }
                    else{
                        parent[it] = node;
                        q.push(it);
                        vis[it] = vis[node]+1;
                    }
                }
            }
            
        }
        return ans < 1e9? ans : -1;
    }
};