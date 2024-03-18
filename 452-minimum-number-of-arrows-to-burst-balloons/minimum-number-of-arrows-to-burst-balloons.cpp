class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size(), ans=0;
        for(int i=0;i<n;i++){
            if(i<n-1 && points[i][1]>= points[i+1][0]){
                points[i+1][0]=points[i][1];
                points[i+1][1]=min(points[i][1],points[i+1][1]);
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};
// 1,6 2,8 7,12 10,16
// 2,6 7,8 10,12
// 1,6 2,13 7,12 10,16
// 1,6 2,13 7,12