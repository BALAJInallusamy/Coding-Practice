class Solution {
public:
    int rec(int i, int n, vector<int>& heights, int bricks, int ladders,
             vector<vector<vector<int>>>& dp){
        
        if(i==n-1) return i;
        if(ladders==0 && bricks<heights[i+1]-heights[i]) return i;
        if(dp[i][bricks][ladders]!=-1) return dp[i][bricks][ladders]; 
        
        if(heights[i]>=heights[i+1]) 
            return dp[i][bricks][ladders]=rec(i+1,n,heights,bricks,ladders,dp);

        int brickuse=0;
        if(bricks>=heights[i+1]-heights[i]) 
            brickuse+=rec(i+1,n,heights,bricks-heights[i+1]+heights[i],ladders,dp);
        
        int ladderuse=0;
        if(ladders>0) 
            ladderuse=rec(i+1,n,heights,bricks,ladders-1,dp);
        return dp[i][bricks][ladders]=max(ladderuse,brickuse);
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        vector<vector<vector<int>>> 
            dp(n,vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1)));

            
        return rec(0,n,heights,bricks,ladders,dp);
    }
};
