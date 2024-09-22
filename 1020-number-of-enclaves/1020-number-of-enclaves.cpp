class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //first row,col and last row ,col
                if(i == 0 || i==n-1 || j==0 || j == m-1){
                   if(!vis[i][j] && grid[i][j] == 1){
                      vis[i][j]  = 1;
                       q.push({i,j});
                   }
                }
            }
        }
        
        
        int delRow[] = {0,-1,0,1};
        int delCol[] = {-1,0,1,0};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            for(int i=0;i<4;i++)
            {
                int r = row + delRow[i];
                int c = col + delCol[i];
                
                if(r>=0 && r<n && c>=0 && c<m && vis[r][c] == 0 && grid[r][c] == 1){
                    vis[r][c] = 1;
                    q.push({r,c});
                }
            }
        }
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] == 0 && grid[i][j]== 1){
                    count++;
                }
            }
        }
        
        return count;
    }
};