class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int m) {
        int n=hand.size();
        sort(hand.begin(),hand.end());
        unordered_map<int,int> mp;

        for(auto it:hand) mp[it]++;
        
        if(n%m !=0) return false;

        int i=0, j=0;
        while(i<n){

            while(i<n && mp[hand[i]]<=0 ){ 
                i++;
                }
            if(i==n) break;

            mp[hand[i]]--;

            j=hand[i]+1;

            for(int k=1; k<m; k++ ){

                if(mp[j]<=0) return false;
                else{
                    mp[j++]--;
                }
            }
            i++;
        }
        return true;
    }
};
// 0 1 2 3 4 5 6 7 8
// 1 2 2 3 3 4 6 7 8