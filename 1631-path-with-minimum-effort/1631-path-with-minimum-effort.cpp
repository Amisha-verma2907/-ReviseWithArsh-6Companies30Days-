class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        int r = heights.size();
        int c = heights[0].size();
        
        vector<vector<int>>dist(r,vector<int>(c,1e9));
        
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        
        int dr[4] = {0,-1,0,1};
        int dc[4] = {-1,0,1,0};
        
        while(!pq.empty()){
            auto  top = pq.top();
            int d = top.first;
            int r1 = top.second.first;
            int c1 = top.second.second;
            pq.pop();
            
            if(r1 == r-1 && c1 == c-1){
                return d;
            }
            for(int i=0;i<4;i++)
            {
                int nrow = r1 + dr[i];
                int ncol = c1 + dc[i];
                
                if(nrow<r && nrow>=0 && ncol < c && ncol >=0 ){
                    int newEffort = max(d,abs(heights[r1][c1] - heights[nrow][ncol]));
                    
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                       pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                    
                }
                
            }
            
        }
        
        return 0;
        
    }
};