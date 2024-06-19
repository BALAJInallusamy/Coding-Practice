class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        vector<vector<int>> all(n,vector<int> (2));
        for(int i=0;i<n;i++){
            all[i]={ difficulty[i],profit[i] };
        }
        sort(all.begin(),all.end(),[](vector<int>& a, vector<int>& b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]>b[1];
        });
        int ans=0;
        sort(worker.rbegin(),worker.rend());
        int m=worker.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(all[j][0]<=worker[i]) {
                    ans+=all[j][1];
                    break;
                }
            }
        }
        return ans;
    }
};