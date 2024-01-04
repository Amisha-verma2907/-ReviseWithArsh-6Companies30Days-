class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        vector<vector<int>>grid( row , vector<int> (col,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==1)
                {
                    grid[i][j]=0;
                    q.push({i,j});   
                }
            }
        }
        while(!q.empty()){
            
            int dr[4] = {0,0,-1,1};
            int dc[4] = {-1,1,0,0};
            int row1 = q.front().first;
            int col1=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int rr=row1+dr[i];
                int cc=col1+dc[i];
                if(rr>=0 && rr<row && cc>=0 && cc<col && grid[rr][cc]<0)
                {
                    grid[rr][cc]=1+grid[row1][col1];
                    q.push({rr,cc});
                }
            }
        }
        return grid;
    }
};