class Solution {
public:
    //basic recursion approach with TC: O(3^N) SC: O(M*N)
//     int minimumPath(vector<vector<int>>& matrix,int row,int col){
//         if(col < 0 || col>=matrix[0].size()){
//             return 1e9;
//         }
        
//         if(row==0){
//             return matrix[0][col];
//         }
        
//         int s = matrix[row][col] + minimumPath(matrix,row-1,col);
//         int ld = matrix[row][col] + minimumPath(matrix,row-1,col-1);
//         int rd = matrix[row][col] + minimumPath(matrix,row-1,col+1);
        
//         return min(s,min(ld,rd));
//     }
    
    //memoization approach TC: O(M*N) SC: O(M*N) + O(N)
    int minimumPath(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>&dp){
        if(col < 0 || col>=matrix[0].size()){
            return 1e9;
        }
        
        if(row==0){
            return matrix[0][col];
        }
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int s = matrix[row][col] + minimumPath(matrix,row-1,col,dp);
        int ld = matrix[row][col] + minimumPath(matrix,row-1,col-1,dp);
        int rd = matrix[row][col] + minimumPath(matrix,row-1,col+1,dp);
        
        return dp[row][col] = min(s,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         vector<vector<int>>dp(m,vector<int>(n,-1));
        
//         int mini = 1e8;
        
//         for(int j=0;j<n;j++)
//         {
//            mini = min(mini,minimumPath(matrix,m-1,j,dp)); 
//         }
//         return mini;
        
        
       //Tabulation TC: O(M*N) + O(N)  SC: O(M*N) 
        
//         int m = matrix.size();
//         int n = matrix[0].size();
        
        
//         vector<vector<int>>dp(m,(vector<int>(n,-1)));
        
//         for(int j=0;j<n;j++)
//         {
//             dp[0][j] = matrix[0][j];
//         }
        
//         for(int i=1;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 int s = matrix[i][j] + dp[i-1][j];
//                 int ld = matrix[i][j];
//                 if(j-1>=0){
//                      ld  += dp[i-1][j-1];
//                 }else{
//                     ld+=1e8;
//                 }
//                 int rd = matrix[i][j] ;
//                 if(j+1<n){
//                      rd += dp[i-1][j+1];
//                 }else{
//                     rd += 1e8;
//                 }
                
//                 dp[i][j] = min(s,min(ld,rd));
//             }
//         }
        
//         int mini = 1e8;
        
//         for(int j=0;j<n;j++)
//         {
//             mini = min(mini,dp[m-1][j]);
//         }
        
//         return mini;
        
        
        //space optimization
        
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        vector<int>prev(n,-1);
        
        for(int j=0;j<n;j++)
        {
            prev[j] = matrix[0][j];
        }
        
        vector<int>cur(n,-1);
        
        for(int i=1;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                int s = matrix[i][j] + prev[j];
                int ld = matrix[i][j];
                if(j-1>=0){
                     ld  += prev[j-1];
                }else{
                    ld+=1e8;
                }
                int rd = matrix[i][j] ;
                if(j+1<n){
                     rd += prev[j+1];
                }else{
                    rd += 1e8;
                }
                
                cur[j] = min(s,min(ld,rd));
            }
            prev  = cur;
        }
        
        int mini = 1e8;
        
        for(int j=0;j<n;j++)
        {
            mini = min(mini,prev[j]);
        }
        
        return mini;
    }
};