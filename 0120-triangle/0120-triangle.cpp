// class Solution {
// public:
//     int sum(vector<vector<int>>& triangle,int m,int n,vector<vector<int>>&dp){
//         if(m==0 && n==0){
//             return triangle[0][0];
//         }    
        
//         if(m<0 || n<0 || n>m){
//             return INT_MAX;
//         }
        
//         if(dp[m][n] != -1){
//             return dp[m][n];
//         }
    
//         int up = sum(triangle,m-1,n,dp);
//         int dg = sum(triangle,m-1,n-1,dp);
        
//         return dp[m][n] = triangle[m][n] + min(up,dg);
//     }
    
    
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = triangle.size();
//         int n = triangle[0].size();
        
        //vector<vector<int>>dp(m,vector<int>(n+1,-1));
        
        // int mini = INT_MAX;
        // for(int i=0;i<m;i++)
        // {
        //    mini = min(mini,sum(triangle,m-1,i,dp));
        // }
//         vector<vector<int>> dp(m);
//         for (int i = 0; i < m; ++i) {
//             dp[i] = vector<int>(i + 1, -1);  // Each row i has i+1 elements
//         }
//         int mini = INT_MAX;
//         for (int i = 0; i < triangle[m - 1].size(); ++i) {
//             mini = min(mini, sum(triangle, m - 1, i, dp));
//         }
        
//         return triangle[0][0] + sum(triangle,0,0);
        
        
//         // return mini;
//     }
// };





class Solution {
public:
    // Recursive function to find the minimum path sum
    int findMinPath(vector<vector<int>>& triangle, int i, int j,vector<vector<int>>&dp) {
        int n = triangle.size();
        
        // Base case: If we reach the last row, return the element
        if (i == n - 1) {
            return triangle[i][j];
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        // Recursively calculate the minimum path sum for the next row
        int down = findMinPath(triangle, i + 1, j,dp);       // Move down
        int diagonal = findMinPath(triangle, i + 1, j + 1,dp);  // Move diagonally
        
        // Return the current element + the minimum of the two possible paths
        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size();
        
        // Start from the top of the triangle (0, 0)
        //vector<vector<int>>dp(m,vector<int>(n,-1));
        
        vector<vector<int>> dp(m);
        for (int i = 0; i < m; ++i) {
            dp[i] = vector<int>(i + 1, -1);  // Each row i has i+1 elements
        }
        
        return findMinPath(triangle, 0, 0,dp);
    }
};
