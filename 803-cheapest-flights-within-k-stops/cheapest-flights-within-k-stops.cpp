class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<int>distance(n+1,INT_MAX);
        //this is for setting the distance array with INT_MAX means infinity
        unordered_map<int,vector<pair<int,int>>>adj;//this is for adjacency list
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});//this is for pushing in the adjacency list
        }
        queue<pair<int,int>>q;
        q.push({src,0});//this is for pushing in the queue
        distance[src]=0;
        while(!q.empty()&&k>=0)
        {
            int n=q.size();
            while(n--)
            {
                auto it=q.front();//getting the front of the queue
                int node=it.first;//this is for node
                int dista=it.second;//this is for distance
                q.pop();
                for(auto itr:adj[node])//exploring all its neighbour
                {
                    int nod=itr.first;
                    int di=itr.second;
                    if(di+dista<distance[nod])
                    {
                        distance[nod]=di+dista;
                        q.push({nod,distance[nod]});
                    }
                }
            }
            k--;
        }
        if(distance[dst]>=INT_MAX)
        {
            return -1;
        }
        return distance[dst];
    }
};