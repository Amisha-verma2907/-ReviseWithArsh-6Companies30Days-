class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&board,int delRow[],int delCol[]){
        vis[row][col] = 1;
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,vis,board,delRow,delCol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        
        int delRow[] = {0,-1,0,1};
        int delCol[] = {-1,0,1,0};
        for(int i=0;i<r;i++)
        {
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,vis,board,delRow,delCol);
            }
            if(!vis[i][c-1] && board[i][c-1] == 'O'){
                dfs(i,c-1,vis,board,delRow,delCol);
            }
        }
        
        for(int i=0;i<c;i++)
        {
            if(!vis[0][i] && board[0][i] == 'O'){
                dfs(0,i,vis,board,delRow,delCol);
            }
            if(!vis[r-1][i] && board[r-1][i] == 'O'){
                dfs(r-1,i,vis,board,delRow,delCol);
            }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
        
    }
};