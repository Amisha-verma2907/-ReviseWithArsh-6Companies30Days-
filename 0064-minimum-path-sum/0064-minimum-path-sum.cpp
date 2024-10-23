class Solution {
public:
    int sum(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
        if (m == 0 && n == 0) {
            return grid[0][0];
        }
        
        if (m < 0 || n < 0) {
            return INT_MAX;  // Return a large value for invalid cells
        }
        
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        
        // Calculate the minimum path sum coming from the top or the left
        int up = sum(grid, m - 1, n, dp);
        int left = sum(grid, m, n - 1, dp);
        
        int result = grid[m][n] + min(up, left);  // Choose the smaller of the two valid paths
        
        return dp[m][n] = result;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        //Tabulation method
//         int m = grid.size();
//         int n = grid[0].size();
        
//         // Initialize a DP table with -1
//         vector<vector<int>> dp(m, vector<int>(n, -1));
        
        
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++){
//                 if(i==0 && j==0){
//                     dp[0][0] = grid[0][0];
//                 }
//                 else{
//                     int up = INT_MAX;
//                     int left = INT_MAX;
                    
//                     if(i> 0){
//                         up = dp[i-1][j];
//                     }
//                     if(j>0){
//                         left = dp[i][j-1];
//                     }
                    
//                     dp[i][j] = grid[i][j] + min(up,left);
//                 }
//             }
//         }
        
//         return dp[m-1][n-1];
        
        //memoization method
        // Start the recursive sum calculation from the bottom-right corner
       // return sum(grid, m - 1, n - 1, dp);
        
        
        //space optimization
        
        int m = grid.size();
        int n = grid[0].size();
        
        // Initialize a DP table with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        vector<int>prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,0);
            
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[0] = grid[0][0];
                }
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    
                    if(i> 0){
                        up = prev[j];
                    }
                    if(j>0){
                        left = temp[j-1];
                    }
                    
                   temp[j] = grid[i][j] + min(up,left);
                }
            }
            prev = temp;
        }
        
        return prev[n-1];
    }
};
