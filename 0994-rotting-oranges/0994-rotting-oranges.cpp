class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<int,pair<int,int>>>q;
        
      int n = grid.size();
      int m = grid[0].size();
        
      vector<vector<int>>vis(n,vector<int>(m,0));
        
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(grid[i][j] == 2){
                  vis[i][j] = 1;
                  q.push({0,{i,j}});
              }
          }
      }
        
      int row[] = {-1,0,1,0};
      int col[] = {0,1,0,-1};
      
        int tm = 0;
      while(!q.empty()){
          int t = q.front().first;
          int r = q.front().second.first;
          int c = q.front().second.second;
          
          tm = max(t,tm);
          
          q.pop();
          for(int i=0;i<4;i++)
          {
              int rowi = r + row[i];
              int coli = c + col[i];
              
              if(rowi>=0 && rowi<n && coli >=0 && coli<m && grid[rowi][coli] == 1 && vis[rowi][coli] == 0)
              {
                  vis[rowi][coli] = 1;
                  
                  q.push({t+1,{rowi,coli}});
              }
          }
      }
        
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(grid[i][j] == 1 && vis[i][j] != 1)
              {
                  return -1;
              }
          }
      }
        
      return tm;
    }
};