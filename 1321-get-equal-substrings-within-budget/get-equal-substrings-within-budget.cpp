class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        vector<int> hash(n);
        for(int i=0;i<n;i++){
            hash[i]=abs(s[i]-t[i]);
        }
        for(auto it:hash) cout<<it<<" ";
        cout<<endl;
        for(int i=1;i<n;i++){
            hash[i]+=hash[i-1];
        }
        for(auto it:hash) cout<<it<<" ";
        cout<<endl;
        int l=0,r=0,cost=0,ans=0;


        for(r=l;l<n && r<n;){
            if(l>r){
                r=l;
            }
            int temp=0;
            if(l>0) temp=hash[l-1];
            cost=hash[r]-temp;

            if(cost>maxCost){
                l++;
            }
            else{
                cout<<hash[l]<<" "<<hash[r]<<endl;
                ans=max(ans,r-l+1);
                r++;
            }
        }
        return ans;
    }
};