class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n= tokens.size();
        int ans=0, l=0, r=n-1,score=0;
        while( l<=r ){
            if( power >= tokens[l] ){
                ans++;
                power-= tokens[l];
                l++;
                score=max(ans,score);
            }
            else if (ans>0) ans--, power+= tokens[r], r--,score=max(ans,score);
            else break;
        }
        return score;
    }
};