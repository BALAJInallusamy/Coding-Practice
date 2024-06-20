class Solution {
public:
    bool help(int mid, vector<int>& pos, int m, int n){
        int prev= pos[0];
        m--;
        for(int i=1;i<n && m>0;i++){
            if( pos[i]-prev >= mid ) prev= pos[i], m--;
        }
        if(m) return false;
        return true;
    }
    int maxDistance(vector<int>& pos, int m) {
        int n=pos.size();
        sort(pos.begin(),pos.end());
        int l=1,r=1,mid,ans=1;
        r= pos[n-1] - pos[0];
        while(l<=r){
            mid=(l-r)/2+r;
            if( help( mid, pos, m, n) ) ans=mid,l=mid+1;
            else r = mid-1;
        }
        return ans;
    }

};