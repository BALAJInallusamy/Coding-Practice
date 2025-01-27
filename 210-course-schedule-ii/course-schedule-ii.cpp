class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> path(n);
        vector<int> in(n);
        for(auto it:pre) in[it[0]]++ ,path[it[1]].push_back(it[0]);
        vector<int> ans;
        function<void(int)> fun=[&](int x){
            for(auto it: path[x]){ 
                if(--in[it] == 0){
                    in[it] = n+1;
                    ans.push_back(it);
                    fun(it);
                }
            }
            return;
        };
        for(int i = 0 ; i< n ; i++){
            if(in[i] == 0 ) ans.push_back(i),fun(i);
        }
        // for(auto it:ans) cout<<it<<" ";
        if(ans.size() == n ) return ans ; 
        return {};
        
    }
};