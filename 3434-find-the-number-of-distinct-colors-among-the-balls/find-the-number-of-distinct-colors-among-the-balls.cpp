class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> color_count,hash;
        int n=queries.size();
        vector<int> ans(n);
        int count=0;

        for(int i=0;i<n;i++){

            int paint=queries[i][1];
            int ball=queries[i][0];

            color_count[paint]++;
            if(color_count[paint] ==1 ) count++;
            if( hash.find(ball)!= hash.end() ){
                color_count[hash[ball]] --;
                if( color_count[hash[ball]] ==0 ) count--;
            }
            hash[ball]=paint;
            ans[i]=count;
        }
    return ans;
    }
    
};

// mp[4]=  h[1]=4
// mp[5]=1 h[2]=5
// mp[3]=1 h[1]=3