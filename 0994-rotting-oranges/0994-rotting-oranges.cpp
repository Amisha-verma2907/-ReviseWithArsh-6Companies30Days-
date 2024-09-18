class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        
        int vis[row][col];
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        
        int r[] = {0,-1,0,1};
        int c[]= {-1,0,1,0};
        
        int tm = 0;
        while(!q.empty()){
            int r1 = q.front().first.first;
            int c1 = q.front().first.second;
            
            int t = q.front().second; 
            
            tm = max(t,tm);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int finalRow = r1+r[i];
                int finalCol = c1+c[i];
                
                if(finalRow>=0 && finalRow<row && finalCol >= 0 && finalCol <col && grid[finalRow][finalCol] == 1 && vis[finalRow][finalCol] == 0){
                    q.push({{finalRow,finalCol},t+1});
                    vis[finalRow][finalCol] = 2;
                }
            }
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        
        return tm;
    }
};