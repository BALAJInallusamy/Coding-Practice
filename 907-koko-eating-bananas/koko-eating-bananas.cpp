class Solution {
public:
    bool help(int mid, vector<int>& piles, int h){
        int count=0;
        for(int i = 0 ; i<piles.size(); i++){
            count+= piles[i]/mid;
            if(piles[i]%mid>0) count++;
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int ans = r;
        while(l<=r){
            int mid = (l-r)/2 +r;
            if(help(mid,piles,h)){
                ans = min(ans,mid);
                r = mid-1;
            }
            else l =mid+1;
        }
        return ans;
    }
};