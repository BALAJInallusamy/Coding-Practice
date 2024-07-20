class Solution {
public:
    vector<int> f;
    int find(int x){
        if(x!=f[x]) f[x] = find(f[x]);
        return f[x];
    }
    void uni(int i, int j){
        i = find(i);
        j = find(j);
        if(i!=j){
            f[j] = i;
        }
    }
    vector<bool> areConnected(int n, int t, vector<vector<int>>& queries) {
        vector<vector<int>> factor(n+1);
        for(int i=0;i<=n;i++){
            f.push_back(i);
        }
        for(int i=t+1;i<=n;i++){
            
            for(int j = i*2 ; j<=n ; j+=i){
                uni(i,j);
            }
        }
        //for(auto it:f) cout<<it<<" ";
        vector<bool> ans={};
        for(auto it:queries) {
            if(find(it[0]) == find(it[1])) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};