class Solution {
public:
    int rec(int past,int i,int n, vector<pair<int,int>>& bi){
        if(i==n) return 0;
        int pick=0;
        if((bi[i].first && past & bi[i].first) ==0 )
            pick += bi[i].second + rec(past+bi[i].first, i+1,n,bi);
        int np=rec(past,i+1,n,bi);
        return max(pick,np);
    }

    int maxLength(vector<string>& arr) {
        int n=arr.size(),temp;
        vector<pair<int,int>> bi(n,{0,0});
        for(int i=0;i<n;i++){
            for(int j=0;j<arr[i].size();j++){
                temp=1<<(arr[i][j]-'a');
                if(bi[i].first &temp){ bi[i]={0,0}; break;}
                else bi[i].first+=temp, bi[i].second++;
            }
        }
        return rec(0,0,n,bi);
    }
};
