class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() - 1] == 1) {
            return -1;
        }
        
        if (grid.size() == 1 && grid[0].size() == 1 && grid[0][0] == 0) {
            return 1;
        }
        
        queue<pair<int,pair<int,int>>>q;
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>> dist(r,vector<int>(c,1e9));
        
        dist[0][0] = 1;
        
        int row[8] = {0,-1,-1,-1,0,1,1,1};
        int col[8] = {-1,-1,0,1,1,1,0,-1};
        
        q.push({1,{0,0}});
        
        while(!q.empty()){
            auto top = q.front();
            
            q.pop();
            int dis = top.first;
            int r1 = top.second.first;
            int c1 = top.second.second;
            
            for(int i=0;i<8;i++){
                int nrow = r1 + row[i];
                int ncol = c1 + col[i];
                
            if(nrow<r && nrow>=0 && ncol<c &&  ncol>=0 && grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol] ){
                dist[nrow][ncol] = 1 + dis;
                
                if(nrow == r-1 && ncol == c-1){
                    return 1 + dis;
                }
                 q.push({dis +1,{nrow,ncol}});
            }
            }
        }
        
        return -1;
        
        
        
    }
};