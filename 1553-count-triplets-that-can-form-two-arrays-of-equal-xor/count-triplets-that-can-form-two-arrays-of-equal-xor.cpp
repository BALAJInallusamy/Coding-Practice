class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // two sub a,b => a^b =0
        // a-b=0;
        int n=arr.size();
        unordered_map<int,vector<int>> mp;
        int x=0 , ans=0;
        for(int i=0; i<n; i++){
            x ^= arr[i];
            if( x==0 ) ans+=i;
            for(int j=0;j<mp[x].size();j++){
                ans+=i-mp[x][j]-1;
            }
            mp[x].push_back(i);
        }
        return ans;
    }
};

// mp[0]=-1,1,3 => 1+1+1
// mp[1]=0,2,4 +=> 1+1+3
// 
// 1 0 1 0 1

// 1+3
// 1+1+1+3
// 1 1 1 1  1
// i j,k   k
// i   j k
// i     j,k
// 2*(3) + 4
// (k-i )
