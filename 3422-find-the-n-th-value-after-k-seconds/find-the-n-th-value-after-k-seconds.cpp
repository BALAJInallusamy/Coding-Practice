int mod=1e9+7;
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<long long int> v(n,1);
        for(int i=0;i<k;i++){
            for(int j=1;j<n;j++){
                v[j]=(v[j]+v[j-1])%mod;
            }
        }
        return v[n-1];
    }
};

//  1 .... . . 1
//  1 a[1]+a[0]
// //    n-1