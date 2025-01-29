class Solution {
public:
    vector<long long> rec(int node ,int parent, vector<vector<int>>& path, int seat){
        if( path[node].size()==1 ){
            return {1,1};
        }
        long long count = 1 , fuel = 0;
        for(auto it:path[node]){
            if(it==parent) continue;
            vector<long long> res = rec(it,node,path, seat);
            count+= res[0];
            fuel += res[1];
        }
        fuel+= count/seat ;
        fuel+= (count%seat!=0);
        return {count, fuel};
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> path(n);
        for(auto it: roads){
            path[it[0]].push_back(it[1]);
            path[it[1]].push_back(it[0]);
        }
        long long ans = 0;
        for(auto it:path[0]){
        ans += rec(it,0,path,seats)[1];
        }
        return ans;
    }
};