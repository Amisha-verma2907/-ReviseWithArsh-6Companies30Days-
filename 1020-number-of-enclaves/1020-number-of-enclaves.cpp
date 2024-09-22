class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid){
        vis[row][col] = 1;
        
        int r = grid.size();
        int c = grid[0].size();
        
         int delRow[] = {0,-1,0,1};
         int delCol[] = {-1,0,1,0};
        
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol =  col + delCol[i];
            
            if(nrow >=0 && nrow<r && ncol>=0 && ncol<c && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,vis,grid);
            }
        }
        
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         vector<vector<int>>vis(n,vector<int>(m,0));
        
        
//         queue<pair<int,int>>q;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 //first row,col and last row ,col
//                 if(i == 0 || i==n-1 || j==0 || j == m-1){
//                    if(!vis[i][j] && grid[i][j] == 1){
//                       vis[i][j]  = 1;
//                        q.push({i,j});
//                    }
//                 }
//             }
//         }
        
        
//         int delRow[] = {0,-1,0,1};
//         int delCol[] = {-1,0,1,0};
        
//         while(!q.empty()){
//             int row = q.front().first;
//             int col = q.front().second;
            
//             q.pop();
//             for(int i=0;i<4;i++)
//             {
//                 int r = row + delRow[i];
//                 int c = col + delCol[i];
                
//                 if(r>=0 && r<n && c>=0 && c<m && vis[r][c] == 0 && grid[r][c] == 1){
//                     vis[r][c] = 1;
//                     q.push({r,c});
//                 }
//             }
//         }
        
//         int count=0;
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(vis[i][j] == 0 && grid[i][j]== 1){
//                     count++;
//                 }
//             }
//         }
        
//         return count;
        
        
        int n= grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i == 0 || i== n-1 || j==0 || j== m-1){
                    if(vis[i][j] == 0 && grid[i][j] == 1){
                        dfs(i,j,vis,grid);
                    }
                }
            }
        }
        
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    count++;
                }
            }
        }
        
        return count;
    }
};