class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{src,0}});
        
        vector<int>dist(n,1e9);
        
        dist[src] = 0;
        while(!q.empty()){
            auto top  = q.front();
            
            int stops = top.first;
            int node = top.second.first;
            int dis = top.second.second;
            
            q.pop();
            
            if(stops > k )continue;
            
            for(auto it:adj[node]){
                int adjNode = it.first;
                int d = it.second;
                
                if(dis + d <dist[adjNode] && stops<=k){
                    dist[adjNode] = dis + d;
                    q.push({stops+1,{adjNode,dis+d}});
                }
            }
        }
        
        if(dist[dst] ==1e9)return -1;
        return dist[dst];
    }
};