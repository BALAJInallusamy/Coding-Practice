class Solution {
public:
    int minimumChairs(string s) {
        int ans=0,count=0;
        for(auto it:s){
            if(it=='E') count=max(count,++ans);
            else ans--;
        }
        return count;
    }
};

