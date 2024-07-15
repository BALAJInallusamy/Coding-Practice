class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n);
        queue<int> q;
        q.push(0);
        while(q.size()){
            int top = q.front();
            q.pop();
            if(vis[top]) continue;
            else{
                vis[top] ++ ;
                for(auto it: rooms[top]){
                    q.push(it);
                }
            }
        }
        for(auto it:vis) if(it == 0) return false;
        return true;
    }
};