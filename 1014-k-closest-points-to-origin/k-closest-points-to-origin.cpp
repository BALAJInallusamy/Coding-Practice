class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int >> dis(n,vector<int >(2));
        for( int i= 0 ; i<n ;i++){
            
            dis[i] = { points[i][0]*points[i][0] + points[i][1]*points[i][1] , i };
        }
        sort(dis.begin(),dis.end());
        vector<vector<int>> ans;
        int i =0;
        while(i<k){
            ans.push_back(points[dis[i][1]]);
            i++;
        }
        return ans;
    }
};