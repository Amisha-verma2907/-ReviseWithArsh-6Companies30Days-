class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& ans,vector<vector<int>>& image, int color,int initialColor,int delRow[],int delCol[]){
        ans[r][c] = color;
        
        int row = image.size();
        int col = image[0].size();
        
        for(int i=0;i<4;i++)
        {
            int newRow = r+delRow[i];
            int newCol = c+delCol[i];
            
            if(newRow>=0 && newRow<row && newCol>=0 && newCol<col && image[newRow][newCol] == initialColor && ans[newRow][newCol] != color)
            {
                dfs(newRow,newCol,ans,image,color,initialColor,delRow,delCol);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
         vector<vector<int>> ans = image;
         int initialColor = image[sr][sc];
        
        int delRow[] = {0,-1,0,1};
        int delCol[] = {-1,0,1,0};
        dfs(sr,sc,ans,image,color,initialColor,delRow,delCol);
        
        return ans;
        
    }
};