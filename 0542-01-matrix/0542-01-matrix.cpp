class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        
        vector<vector<int>>vis(r,vector<int>(c,0));
        vector<vector<int>>dis(r,vector<int>(c,0));
        
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }else{
                    vis[i][j] = 0;
                }
            }
        }
        
        
        int delRow[] = {0,-1,0,1};
        int delCol[] = {-1,0,1,0};
        
        while(!q.empty()){
            int row = q.front().first.first;
        int col = q.front().first.second;
        
        int steps = q.front().second;
            dis[row][col] = steps;
            q.pop();
            for(int i=0;i<4;i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                
                if(newRow>=0 && newRow<r && newCol >=0 && newCol<c  && vis[newRow][newCol] ==0){
                    vis[newRow][newCol] = 1;
                    q.push({{newRow,newCol},steps+1});
                    
                }
                
            }
            
        }
        
        return dis;
    }
};