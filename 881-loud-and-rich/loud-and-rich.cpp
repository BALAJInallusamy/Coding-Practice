class Solution {
public:
    pair<int,int> rec(int child, vector<vector<int>>& graph, vector<int>& quiet,vector<int>& ans){

        if(graph[child].size()==0) return { quiet[child],child };
        else{

            pair<int,int> q= { quiet[child], child } , temp;

            for(auto it:graph[child] ){

                if(it<child) temp={ quiet[ans[it]],ans[it] };
                else temp = rec(it,graph,quiet,ans);

                q = q.first > temp.first ? temp:q;
            }
            return q;
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[i]=i;
        if(richer.size()==0) return ans;

        vector<vector<int>> graph(n);

        for(int i=0;i<richer.size();i++){

            graph[richer[i][1]].push_back(richer[i][0]);

        }

        for(int i=0;i<n;i++){
            ans[i]=rec(i,graph,quiet,ans).second;
        }
        return ans;
    }
};

// 0=>0
// 1=>1,0