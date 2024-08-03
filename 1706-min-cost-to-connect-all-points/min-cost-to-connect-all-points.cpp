int man(vector<int>& p1, vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> parent(n);
        for(int i = 0 ;i< n; i++) parent[i] = i;

        function<int(int)> find =[&] (int i) {
            if(i == parent[i]) return i;
            else parent[i] = find(parent[i]);
            return parent[i];
        };
        auto uni = [&] (int a, int b){
            a = find(a);
            b = find(b);
            if (a == b) return false;
            else{
                parent[a] = b;
                return true;
            }
        };
        vector<vector<int>> edges;

        for(int i = 0 ; i<n ; i++){
            for(int j= i+1 ; j < n ; j++)
            edges.push_back({ man( points[i], points[j] ), i , j });
        }
        int ans = 0, count = 0;
        sort(edges.begin() , edges.end());
        for( auto it : edges){
            auto w  = it[0], u = it[1] , v = it[2];
            if( uni(u,v) ){
                ans += w;
                count++;
            }
            if( count == n-1) return ans;
        }
        return 0;

    }
};