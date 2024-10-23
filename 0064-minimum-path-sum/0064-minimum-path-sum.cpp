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
        int m = grid.size();
        int n = grid[0].size();
        
        // Initialize a DP table with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // Start the recursive sum calculation from the bottom-right corner
        return sum(grid, m - 1, n - 1, dp);
    }
};
