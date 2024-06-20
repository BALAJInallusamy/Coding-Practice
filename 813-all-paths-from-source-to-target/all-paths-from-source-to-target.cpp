class Solution {
public:
    vector<vector<int>> rec(int cur,int n, vector<vector<int>>& graph, vector<vector<vector<int>>>& path){

        if(path[cur].size() != 0) return path[cur];
        for(auto it:graph[cur]){
            vector<vector<int>> temp;

            temp= rec(it,n,graph,path);
            int m=temp.size();


            for(int i=0;i<m;i++){
                vector<int> pusher (1,cur);
                for(int j=0;j<temp[i].size();j++){
                    pusher.push_back(temp[i][j]);
                }
                path[cur].push_back(pusher);
            }
        }
        return path[cur];
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<vector<int>>> path(n);
        path[n-1]={{n-1}};
        path[0]=rec(0,n,graph,path);
        return path[0];
    }
};